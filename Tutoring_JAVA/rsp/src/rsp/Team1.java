package rsp;

public class Team1 implements Strategy{
	@Override
	public int think() {
		// TODO Auto-generated method stub
		return (int) (Math.random() * 2);
	}
}
