import java.util.*;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;

public class Logger {
    private final String LOGFILE = "log.txt";
    private PrintWriter writer;
    private static Logger instance;
    public static Logger getInstance() {
        if (instance == null) synchronized (Logger.class){
            if (instance == null) instance = new Logger();
            // 1. Logger 인스턴스를 위한 메모리 할당
            // 2. 생성자를 통한 초기화
            // 3. 할당된 메모리를 instance 변수에 할당
        }
        return instance;
    }

    private Logger() {
        try {
            FileWriter fw = new FileWriter(LOGFILE);
            writer = new PrintWriter(fw, true);
        } catch (IOException e) { }
    }

    public void log (String message) {
        System.out.println(this.toString());
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd 'at' HH:mm:ss z");
        Date date = new Date(System.currentTimeMillis());
        writer.println(formatter.format(date)+":"+message);
    }

}
