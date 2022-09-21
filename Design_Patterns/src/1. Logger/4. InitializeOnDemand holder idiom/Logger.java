import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Logger {
        private final String LOGFILE = "log.txt";
        private PrintWriter writer;
        private static Logger instance;
        public Logger() {
            try {
                FileWriter fw = new FileWriter(LOGFILE);
                writer = new PrintWriter(fw, true);
            } catch (IOException e) {}
        }
        public void log (String message) {
            System.out.println(this.toString());
            SimpleDateFormat formatter= new SimpleDateFormat("yyyy-MM-dd 'at' HH:mm:ss z");
            Date date = new Date(System.currentTimeMillis());
            writer.println(formatter.format(date) + " : " + message);
        }

        private static class LazyHolder {
            public static final Logger INSTANCE = new Logger();
        }
        public static Logger getInstance() {
            return LazyHolder.INSTANCE;
        }
}
