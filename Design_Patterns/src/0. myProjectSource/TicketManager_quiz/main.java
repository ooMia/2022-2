public class main<NUM> {
	public static final int NUM = 5;
	public static void main(String[] args) {
		User[] users = new User[NUM];

		for (int i=0;i<NUM; ++i){
			users[i] = new User("user"+i);
			users[i].start();
			System.out.println(TicketManager.getInstance());
		}
	}
}
