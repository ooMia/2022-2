public class Printer6 {
	public Printer6() {}
	public static void printWithPlus(String contents) {
		synchronized (Printer6.class) {
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

	private final Object obj1 = new Object();

	public static void main(String[] args) {
		Printer6 printer = new Printer6();

		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				Printer6.printWithPlus(Thread.currentThread().getName());
			}
		}).start();

		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				Printer6.printWithStar(Thread.currentThread().getName());
			}
		}).start();

	}
}