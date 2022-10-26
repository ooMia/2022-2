package myWork;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.UnsupportedEncodingException;

// keyboard enter key 치면 서버로 전송
class Myaction implements ActionListener  // 내부클래스로 액션 이벤트 처리 클래스
{
	@Override
	public void actionPerformed(ActionEvent e) {
		// Send button을 누르거나 메시지 입력하고 Enter key 치면
		if (e.getSource() == btnSend || e.getSource() == txtInput) {
			String msg = null;
			msg = String.format("[%s] %s\n", UserName, txtInput.getText());
			SendMessage(msg);
			txtInput.setText(""); // 메세지를 보내고 나면 메세지 쓰는창을 비운다.
			txtInput.requestFocus(); // 메세지를 보내고 커서를 다시 텍스트 필드로 위치시킨다
			if (msg.contains("/exit")) // 종료 처리
				System.exit(0);
		}
	}
}
	// 화면에 출력
	public void AppendText(String msg) {
		textArea.append(msg + "\n");
		textArea.setCaretPosition(textArea.getText().length());
	}

	// Windows 처럼 message 제외한 나머지 부분은 NULL 로 만들기 위한 함수
	public byte[] MakePacket(String msg) {
		byte[] packet = new byte[BUF_LEN];
		byte[] bb = null;
		int i;
		for (i = 0; i < BUF_LEN; i++)
			packet[i] = 0;
		try {
			bb = msg.getBytes("euc-kr");
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.exit(0);
		}
		for (i = 0; i < bb.length; i++)
			packet[i] = bb[i];
		return packet;
	}

	// Server에게 network으로 전송
	public void SendMessage(String msg) {
		try {
			// dos.writeUTF(msg);
			byte[] bb;
			bb = MakePacket(msg);
			dos.write(bb, 0, bb.length);
		} catch (IOException e) {
			AppendText("dos.write() error");
			try {
				dos.close();
				dis.close();
				socket.close();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
				System.exit(0);
			}
		}
	}
}