import java.util.Optional;

public class TicketManager {

    private static int count;
    private static final int LIMITS = 2;
    private static TicketManager instance;

    private TicketManager(){
        count = 0;
    }

    public Optional<Ticket> issue(){
        if (count >= LIMITS) return Optional.empty();
        return Optional.of(new Ticket(count++));
    }

    public static TicketManager getInstance(){
        if (instance == null) instance = new TicketManager();
        return instance;
    }
}
