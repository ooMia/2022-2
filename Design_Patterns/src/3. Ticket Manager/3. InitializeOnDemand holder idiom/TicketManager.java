import java.util.Optional;

public class TicketManager {
    private static TicketManager instance;
    private int count;
    private final int LIMITS = 2;
    private TicketManager() {
        count = 0;
    }

    private static class LazyHolder {
        private static final TicketManager INSTANCE = new TicketManager();
    }
    public static TicketManager getInstance() {
        return LazyHolder.INSTANCE;
    }
    public  synchronized Optional<Ticket> issue() {
        if (count >= LIMITS) return Optional.empty();
        return Optional.of(new Ticket(count++));
    }
}
