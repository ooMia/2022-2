public class Printer4 {
	public Printer4() {}
	public void printWithPlus(String contents) {
		synchronized (obj1) {
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

	public synchronized void printWithStar(String contents) {
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
		Printer4 printer = new Printer4();

		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				printer.printWithPlus(Thread.currentThread().getName());
			}
		}).start();

		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				printer.printWithStar(Thread.currentThread().getName());
			}
		}).start();

	}
}