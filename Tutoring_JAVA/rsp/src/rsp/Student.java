package rsp;

public class Student extends Player{
	
	protected Student(String name) {
		super(name);
		// TODO Auto-generated constructor stub
	}


	
	@Override
	protected String nextMove(Strategy strategy) {
		// TODO Auto-generated method stub
		String res = null;
		
		if (strategy == null) res = super.rsp[1];
		else strategy.think();
		
		return res;
	}

}
