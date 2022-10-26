// JavaChatServer.java
// Java Chatting Server
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;

public class JavaChatServer extends JFrame {
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	JTextArea textArea;
	private JTextField txtPortNumber;

	private ServerSocket socket; // ��������
	private Socket client_socket; // accept() ���� ������ client ����
	private Vector<UserService> UserVec = new Vector<UserService>(); // ����� ����ڸ� ������ ����
	private static final int BUF_LEN = 128; // Windows ó�� BUF_LEN �� ����

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					JavaChatServer frame = new JavaChatServer();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public JavaChatServer() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 338, 386);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(12, 10, 300, 244);
		contentPane.add(scrollPane);

		textArea = new JTextArea();
		textArea.setEditable(false);
		scrollPane.setViewportView(textArea);

		JLabel lblNewLabel = new JLabel("Port Number");
		lblNewLabel.setBounds(12, 264, 87, 26);
		contentPane.add(lblNewLabel);

		txtPortNumber = new JTextField();
		txtPortNumber.setHorizontalAlignment(SwingConstants.CENTER);
		txtPortNumber.setText("30000");
		txtPortNumber.setBounds(111, 264, 199, 26);
		contentPane.add(txtPortNumber);
		txtPortNumber.setColumns(10);

		JButton btnServerStart = new JButton("Server Start");
		btnServerStart.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					socket = new ServerSocket(Integer.parseInt(txtPortNumber.getText()));
				} catch (NumberFormatException | IOException e1) {
					e1.printStackTrace();
				}
				AppendText("Chat Server Running..");
				btnServerStart.setText("Chat Server Running..");
				btnServerStart.setEnabled(false); // ������ ���̻� �����Ű�� �� �ϰ� ���´�
				txtPortNumber.setEnabled(false); // ���̻� ��Ʈ��ȣ ������ �ϰ� ���´�
				AcceptServer accept_server = new AcceptServer();
				accept_server.start();
			}
		});
		btnServerStart.setBounds(12, 300, 300, 35);
		contentPane.add(btnServerStart);
	}

/**
 * ServerSide�� �ؽ�Ʈ ����
 * @param str ������ �ؽ�Ʈ
 * @return void
 */
public void AppendText(String str) {
	textArea.append(str + "\n");
	textArea.setCaretPosition(textArea.getText().length());
}
	
// inner class of JavaChatServer
// ���ο� ������ accept() �ϰ� user thread�� ���� �����Ѵ�.
class AcceptServer extends Thread {
	public void run() {
		while (true) { // ����� ������ ����ؼ� �ޱ� ���� while��
			try {
				AppendText("Waiting new clients ...");
				client_socket = socket.accept(); // accept�� �Ͼ�� �������� ���� �����
				AppendText("���ο� ������ from " + client_socket);
				
				// User�� �ϳ��� Thread ����
				UserService new_user = new UserService(client_socket);
				UserVec.add(new_user); // ���ο� ������ �迭�� �߰�
				new_user.start(); // ���� ��ü�� ������ ����
				AppendText("���� ������ �� " + UserVec.size());
				
			} catch (Exception e) {
				AppendText("accept() error");
				e.printStackTrace();
			}
		}
	}
}

//inner class of JavaChatServer
	// User �� �����Ǵ� Thread
	// Read One ���� ��� -> Write All
	class UserService extends Thread {
		
		private DataInputStream dis;
		private DataOutputStream dos;
		private Socket client_socket;
		private Vector<UserService> user_vc;
		public String UserName = "";
		public String UserStatus;

		public UserService(Socket client_socket) {
			// �Ű������� �Ѿ�� �ڷ� ����
			this.client_socket = client_socket;
			this.user_vc = UserVec;
			try {
				dis = new DataInputStream(client_socket.getInputStream());
				dos = new DataOutputStream(client_socket.getOutputStream());
				
				// /login user1
				byte[] b = new byte[BUF_LEN];
				dis.read(b);
				String line1 = new String(b);
				String[] msg = line1.split(" ");
				UserName = msg[1].trim();
				UserStatus = "O";
				
				AppendText("���ο� ������ " + UserName + " ����");
				WriteOne("Welcome to Java chat server\n"
						+ UserName + "�� ȯ���մϴ�\n");
				WriteAll("["+UserName+"]���� �����߽��ϴ�\n");
				
				// UserService ������ ȣ���� ����Ǹ�,
				// AcceptServer Ŭ�������� ���� ������ user�� UserVec�� �߰��Ѵ�.  
			} catch (Exception e) {
				AppendText("userService error");
				e.printStackTrace();
			}
		}
		
		// Client �� ���� �޼��� ���� 
		public void WriteOne(String msg) {
			try {
				byte[] bb;
				bb = MakePacket(msg);
				dos.write(bb, 0, bb.length);
			} catch (Exception e) {
				AppendText("dos.write() error");
				e.printStackTrace();

				userOut(); // �������� ���� ��ü�� ���Ϳ��� �����
			}
		}
		
		// ��� User�鿡�� ���. ������ UserService Thread�� WriteOne() �� ȣ���Ѵ�.
		public void WriteAll(String str) {
			for (int i = 0; i < user_vc.size(); i++) {
				UserService user = (UserService) user_vc.elementAt(i);
				if (user.UserStatus == "O")
					user.WriteOne(str);
			}
		}

		// ���� ������ User�鿡�� ���. ������ UserService Thread�� WriteONe() �� ȣ���Ѵ�.
		public void WriteOthers(String str) {
			for (int i = 0; i < user_vc.size(); i++) {
				UserService user = (UserService) user_vc.elementAt(i);
				if (user!=this && user.UserStatus == "O")
					user.WriteOne(str);
			}
		}
		

		public void userOut() {
			
			try {
				dos.close();
				dis.close();
				client_socket.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
			
			UserVec.removeElement(this);
			WriteAll("[" + UserName + "]���� ���� �Ͽ����ϴ�.\n");
			AppendText("����� [" + UserName + "] ����. ���� ������ �� " + UserVec.size());
		}

		// Windows ó�� message ������ ������ �κ��� NULL �� ����� ���� �Լ�
		public byte[] MakePacket(String msg) {
			byte[] bb = null;
			try {
				bb = msg.getBytes("EUC-KR");
			} catch (UnsupportedEncodingException e) {
				e.printStackTrace();
			}
			
			byte[] packet = new byte[BUF_LEN];
			int i=0;
			for (; i < bb.length; i++) packet[i] = bb[i];
			for (; i < BUF_LEN; i++) packet[i] = 0;
			return packet;
		}

		public void run() {
			
			while (true) {
				try {
					byte[] b = new byte[BUF_LEN];
					if (dis.read(b) < 0) {
						AppendText("dis.read() < 0 error");
						userOut();
						break;
					}
					
					String msg = new String(b, "euc-kr").trim();
					AppendText(msg);

					String[] args = msg.split(" ");
					if (args.length <= 1) { UserStatus = "O"; }
					else if (args[1].matches("/exit")) { userOut(); break; }
					else if (args[1].matches("/list"))
					{
						WriteOne( "User list\n"
								+ "Name" + "\t" + "Status" + "\n"
								+ "-------------------------------\n");
						for (int i = 0; i < user_vc.size(); i++) {
							UserService user = user_vc.elementAt(i);
							WriteOne(user.UserName + "\t" + user.UserStatus + "\n");
						}
						WriteOne("-------------------------------\n");
					}
					else if (args[1].matches("/sleep" )) { UserStatus = "S"; }
					else if (args[1].matches("/wakeup")) { UserStatus = "O"; }
					else if (args[1].matches("/to"))
					{
						UserService user = null;
						for (UserService u : user_vc)
							if (u.UserName.matches(args[2]) && u.UserStatus.matches("O")) { user = u; break; }
						
						String message = "";
						for (int p = 3; p<args.length; p++) message += (args[p] + " ");
						user.WriteOne("[�ӼӸ�] " + args[0] + " " + message.trim() + "\n");
					}
					else {
						// �Ϲ� �޼���
						UserStatus = "O";
						WriteAll(msg + "\n");
					}
				} catch (IOException e) {
					AppendText("dis.read() error");
					userOut();
					break;
				}
				
			} // while
		} // run
	}
}
