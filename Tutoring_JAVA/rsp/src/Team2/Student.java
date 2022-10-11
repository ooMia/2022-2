package Team2;

public class Student extends Player{
	
	protected Student(String name) {
		super(name);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected String nextMove(Strategy strategy) {//공격권 넘겨주는 함수
		// TODO Auto-generated method stub
		String res = null;
		
		if (strategy == null) res = rsp[1]; //한번도 가위바위보 하지 않았으면 처음을 주먹
		else res = rsp[strategy.think()];
		
		return res;
	}

}