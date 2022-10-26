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

	private ServerSocket socket; // 서버소켓
	private Socket client_socket; // accept() 에서 생성된 client 소켓
	private Vector<UserService> UserVec = new Vector<UserService>(); // 연결된 사용자를 저장할 벡터
	private static final int BUF_LEN = 128; // Windows 처럼 BUF_LEN 을 정의

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
				btnServerStart.setEnabled(false); // 서버를 더이상 실행시키지 못 하게 막는다
				txtPortNumber.setEnabled(false); // 더이상 포트번호 수정못 하게 막는다
				AcceptServer accept_server = new AcceptServer();
				accept_server.start();
			}
		});
		btnServerStart.setBounds(12, 300, 300, 35);
		contentPane.add(btnServerStart);
	}

/**
 * ServerSide에 텍스트 전달
 * @param str 전달할 텍스트
 * @return void
 */
public void AppendText(String str) {
	textArea.append(str + "\n");
	textArea.setCaretPosition(textArea.getText().length());
}
	
// inner class of JavaChatServer
// 새로운 참가자 accept() 하고 user thread를 새로 생성한다.
class AcceptServer extends Thread {
	public void run() {
		while (true) { // 사용자 접속을 계속해서 받기 위해 while문
			try {
				AppendText("Waiting new clients ...");
				client_socket = socket.accept(); // accept가 일어나기 전까지는 무한 대기중
				AppendText("새로운 참가자 from " + client_socket);
				
				// User당 하나씩 Thread 생성
				UserService new_user = new UserService(client_socket);
				UserVec.add(new_user); // 새로운 참가자 배열에 추가
				new_user.start(); // 만든 객체의 스레드 실행
				AppendText("현재 참가자 수 " + UserVec.size());
				
			} catch (Exception e) {
				AppendText("accept() error");
				e.printStackTrace();
			}
		}
	}
}

//inner class of JavaChatServer
	// User 당 생성되는 Thread
	// Read One 에서 대기 -> Write All
	class UserService extends Thread {
		
		private DataInputStream dis;
		private DataOutputStream dos;
		private Socket client_socket;
		private Vector<UserService> user_vc;
		public String UserName = "";
		public String UserStatus;

		public UserService(Socket client_socket) {
			// 매개변수로 넘어온 자료 저장
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
				
				AppendText("새로운 참가자 " + UserName + " 입장");
				WriteOne("Welcome to Java chat server\n"
						+ UserName + "님 환영합니다\n");
				WriteAll("["+UserName+"]님이 입장했습니다\n");
				
				// UserService 생성자 호출이 종료되면,
				// AcceptServer 클래스에서 새로 입장한 user를 UserVec에 추가한다.  
			} catch (Exception e) {
				AppendText("userService error");
				e.printStackTrace();
			}
		}
		
		// Client 한 명에게 메세지 전송 
		public void WriteOne(String msg) {
			try {
				byte[] bb;
				bb = MakePacket(msg);
				dos.write(bb, 0, bb.length);
			} catch (Exception e) {
				AppendText("dos.write() error");
				e.printStackTrace();

				userOut(); // 에러가난 현재 객체를 벡터에서 지운다
			}
		}
		
		// 모든 User들에게 방송. 각각의 UserService Thread의 WriteOne() 을 호출한다.
		public void WriteAll(String str) {
			for (int i = 0; i < user_vc.size(); i++) {
				UserService user = (UserService) user_vc.elementAt(i);
				if (user.UserStatus == "O")
					user.WriteOne(str);
			}
		}

		// 나를 제외한 User들에게 방송. 각각의 UserService Thread의 WriteONe() 을 호출한다.
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
			WriteAll("[" + UserName + "]님이 퇴장 하였습니다.\n");
			AppendText("사용자 [" + UserName + "] 퇴장. 현재 참가자 수 " + UserVec.size());
		}

		// Windows 처럼 message 제외한 나머지 부분은 NULL 로 만들기 위한 함수
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
						user.WriteOne("[귓속말] " + args[0] + " " + message.trim() + "\n");
					}
					else {
						// 일반 메세지
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
