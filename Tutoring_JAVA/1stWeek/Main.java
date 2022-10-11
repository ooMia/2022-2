import src.Player;
import src.Student;

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Hyeon");
        Player p = s1;
        System.out.println(s1.getName());
    }
}