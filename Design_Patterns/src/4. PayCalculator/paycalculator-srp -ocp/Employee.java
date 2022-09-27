public class Employee {
    private String id;
    private int workingHours;
    private int overtimeHours;
    private PayCalculator payCalculator;

    public void setPayCalculator(PayCalculator payCalculator) {
        this.payCalculator = payCalculator;
    }

    public Employee(String id) {
        this.id = id;
        this.workingHours = 0;
        this.overtimeHours = 0;
        this.payCalculator = new BasicPayment();
    }

    public Employee(String id, int workingHours, int overtimeHours) {
        this.id = id;
        this.workingHours = workingHours;
        this.overtimeHours = overtimeHours;
        this.payCalculator = new BasicPayment();
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getWorkingHours() {
        return workingHours;
    }

    public void setWorkingHours(int workingHours) {
        this.workingHours = workingHours;
    }

    public int getOvertimeHours() {
        return overtimeHours;
    }

    public void setOvertimeHours(int overtimeHours) {
        this.overtimeHours = overtimeHours;
    }

    public int calculatePayment() {
        return this.payCalculator.calculatePayment(
                this.getWorkingHours(), this.getOvertimeHours());
    }
}
