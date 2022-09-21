public class Printer3 {
	public Printer3() {}
	public void printWithPlus(String contents) {
		synchronized (this) {
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

	public static void main(String[] args) {
		Printer3 printer = new Printer3();
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
