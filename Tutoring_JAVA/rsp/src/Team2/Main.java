package Team2;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student s1 = new Student("sjiwon_leedayung");
        Player p = s1; //μμΊμ€ν
        
        System.out.println(p.getName() + " : " +p.nextMove(new Game()));
	}

}
