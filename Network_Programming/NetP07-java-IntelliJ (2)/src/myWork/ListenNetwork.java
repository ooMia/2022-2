package myWork;

import java.io.IOException;

// Server Message를 수신해서 화면에 표시
class ListenNetwork extends Thread {
	public void run() {
		while (true) {
			try {
				// String msg = dis.readUTF();
				byte[] b = new byte[BUF_LEN];
				int ret;
				ret = dis.read(b);
				if (ret < 0) {
					AppendText("dis.read() < 0 error");
					try {
						dos.close();
						dis.close();
						socket.close();
						break;
					} catch (Exception ee) {
						break;
					}// catch문 끝
				}
				String	msg = new String(b, "euc-kr");
				msg = msg.trim(); // 앞뒤 blank NULL, \n 모두 제거
				AppendText(msg); // server 화면에 출력
			} catch (IOException e) {
				AppendText("dis.read() error");
				try {
					dos.close();
					dis.close();
					socket.close();
					break;
				} catch (Exception ee) {
					break;
				} // catch문 끝
			} // 바깥 catch문끝

		}
	}
}

