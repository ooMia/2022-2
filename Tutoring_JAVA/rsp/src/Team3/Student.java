package Team3;
import java.util.Random; // Random의 r은 대문자!
public class Student extends Team3.Player implements Team3.Strategy {

	protected Student(String name) {
		super(name);
		// TODO Auto-generated constructor stub
	}

	protected String nextMove() {
		return rsp[think()];
	}

	// student class에서 implements 할거면 미구현 메소드가 포함되어야 해!
	@Override
	public int think() {
		// TODO Auto-generated method stub
		return (int)(Math.random() * 3); // random은 Math 클래스의 메소드야
	}

	@Override
	protected String nextMove(rsp.Strategy strategy) {
		// TODO Auto-generated method stub
		return rsp[think()];
	}

}
