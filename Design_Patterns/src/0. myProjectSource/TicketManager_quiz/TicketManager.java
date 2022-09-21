import java.util.Optional;

public class TicketManager {
	private static TicketManager instance;
	private int count;
	private final int LIMITS = 2;
	private TicketManager() {
		count = 0;
	}
	public synchronized static TicketManager getInstance() {

		if (instance == null) {
			instance = new TicketManager();
		}
		return instance;
	}
	public Optional<Ticket> issue() {
		if (count >= LIMITS) return Optional.empty();
		Ticket t = new Ticket(count);
		count++;
		return Optional.of(t);
	}
}