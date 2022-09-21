public class Printer5 {
	public Printer5() {}
	public static synchronized void printWithPlus(String contents) {
		System.out.println("++++++++++++++++");

		try {
			long sleep = (long) (Math.random() * 100);
			Thread.sleep(sleep);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println(contents);
		System.out.println("++++++++++++++++");
	}

	public static synchronized void printWithStar(String contents) {
		System.out.println("****************");

		try {
			long sleep = (long) (Math.random() * 100);
			Thread.sleep(sleep);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println(contents);
		System.out.println("****************");
	}

	public static void main(String[] args) {
		Printer5 printer = new Printer5();

		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				Printer5.printWithPlus(Thread.currentThread().getName());
			}
		}).start();

		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				Printer5.printWithStar(Thread.currentThread().getName());
			}
		}).start();

	}
}
