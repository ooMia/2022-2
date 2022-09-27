import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Optional;

class CalculatePayMachine extends Frame implements ActionListener, DocumentListener {
    private JLabel idLabel = new JLabel("Employee Id = ", Label.RIGHT);
    private JLabel workingHoursLabel = new JLabel("Working Hours = ", Label.RIGHT);
    private JLabel overTimeHoursLabel = new JLabel("Overtime Hours = ", Label.RIGHT);
    private JLabel payAmountLabel = new JLabel("Pay Amount = ", Label.RIGHT);
    private JTextField tfIdField= new JTextField();
    private JTextField tfWorkingHours = new JTextField();
    private JTextField tfOvertimeHours = new JTextField();
    private JTextField tfResult = new JTextField();
    private JButton calcButton = new JButton("Calculate");
    private JButton updateButton = new JButton("Update");
    private JButton resetButton = new JButton("Reset");
    private JButton end = new JButton("Stop");


    public CalculatePayMachine() {
        super("Payment Calculation");
        this.init();
        this.start();
        this.setSize(500, 250);
        this.setVisible(true);
    }

    public void init() {
        this.setLayout(new GridLayout(6, 1));

        Panel p1 = new Panel(new BorderLayout());
        p1.add("West", idLabel);
        p1.add("Center", tfIdField);
        this.add(p1);

        Panel p2 = new Panel(new BorderLayout());
        p2.add("West", workingHoursLabel);
        p2.add("Center", tfWorkingHours);
        this.add(p2);

        Panel p3 = new Panel(new BorderLayout());
        p3.add("West", overTimeHoursLabel);
        p3.add("Center", tfOvertimeHours);
        this.add(p3);

        Panel p4 = new Panel(new FlowLayout(FlowLayout.CENTER));
        p4.add(calcButton);
        this.add(p4);

        Panel p5 = new Panel(new BorderLayout());
        p5.add("West", payAmountLabel);
        p5.add("Center", tfResult);
        this.add(p5);

        Panel p6 = new Panel(new FlowLayout(FlowLayout.RIGHT));
        p6.add("West", updateButton);
        p6.add(resetButton);
        p6.add(end);
        this.add(p6);
    }

    public void start() {
        calcButton.addActionListener(this);
        resetButton.addActionListener(this);
        tfWorkingHours.getDocument().addDocumentListener(this);
        tfOvertimeHours.getDocument().addDocumentListener(this);
        end.addActionListener(this);
        updateButton.addActionListener(this);
        updateButton.setEnabled(false);
        calcButton.setEnabled(false);
        resetButton.setEnabled(false);
    }

    public boolean isDataEntered() {
        if (tfIdField.getText().trim().length() == 0 ||
                tfWorkingHours.getText().trim().length() == 0 ||
                tfOvertimeHours.getText().trim().length() == 0)
            return false;
        return true;
    }

    @Override
    public void insertUpdate(DocumentEvent e) {
        checkData();
    }

    @Override
    public void removeUpdate(DocumentEvent e) {
        checkData();
    }

    @Override
    public void changedUpdate(DocumentEvent e) {
        checkData();
    }

    private void checkData() {
        calcButton.setEnabled(isDataEntered());
    }

    public void actionPerformed(ActionEvent e) {
        InMemoryRepository repo = InMemoryRepository.getInstance();
        Employee emp = null;
        String id = null;
        int work = 0;
        int overTime = 0;

        if (e.getSource() == end) {
            System.exit(0);
        }
        if (e.getSource() == resetButton) {
            tfIdField.setText("");
            tfWorkingHours.setText("");
            tfOvertimeHours.setText("");
            tfWorkingHours.requestFocus();
            tfResult.setText("");
            resetButton.setEnabled(false);
            return;
        }
        if (e.getSource() == calcButton) {
            id = tfIdField.getText().trim();
//            InMemoryRepository repo = InMemoryRepository.getInstance();
//            Employee emp = null;


                emp = repo.getEmployee(id);
                if (emp == null) {
                    tfIdField.setText("");
                    tfWorkingHours.setText("");
                    tfOvertimeHours.setText("");
                    tfIdField.requestFocus();
                    return;
                }

            try {
                work = Integer.parseInt(tfWorkingHours.getText().trim());
            } catch (NumberFormatException ee) {
                tfWorkingHours.setText("");
                tfWorkingHours.requestFocus();
                return;
            }

            try {
                overTime = Integer.parseInt(tfOvertimeHours.getText().trim());
            } catch (NumberFormatException ee) {
                tfOvertimeHours.setText("");
                tfOvertimeHours.requestFocus();
                return;
            }
            int payAmount = 0;
            payAmount = 10000 * (work + emp.getWorkingHours()) + 15000 * (overTime + emp.getOvertimeHours());
            tfResult.setText(String.valueOf(payAmount));
            resetButton.setEnabled(true);
            updateButton.setEnabled(true);
        }
        if (e.getSource() == updateButton) {
            id = tfIdField.getText().trim();
            emp = repo.getEmployee(id);
            if (emp == null) {
                tfIdField.setText("");
                tfWorkingHours.setText("");
                tfOvertimeHours.setText("");
                tfIdField.requestFocus();
                return;
            }
            try {
                work = Integer.parseInt(tfWorkingHours.getText().trim());
            } catch (NumberFormatException ee) {
                tfWorkingHours.setText("");
                tfWorkingHours.requestFocus();
                return;
            }

            try {
                overTime = Integer.parseInt(tfOvertimeHours.getText().trim());
            } catch (NumberFormatException ee) {
                tfOvertimeHours.setText("");
                tfOvertimeHours.requestFocus();
                return;
            }
            emp.setWorkingHours(work + emp.getWorkingHours());
            emp.setOvertimeHours(overTime + emp.getOvertimeHours());
            repo.writeEmployee(emp);
            repo.printEmployees();
            tfIdField.setText("");
            tfWorkingHours.setText("");
            tfOvertimeHours.setText("");
            tfIdField.requestFocus();
            tfResult.setText("");
            resetButton.setEnabled(false);
            updateButton.setEnabled(false);
            return;
        }
    }
}

