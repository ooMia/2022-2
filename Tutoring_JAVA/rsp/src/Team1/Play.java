package Team1;

import Team2.Game;

class Student extends Player {

    protected Student(String name) {
        super(name);
        // TODO Auto-generated constructor stub
    }

    @Override
    protected String nextMove(Strategy strategy) {
        // TODO Auto-generated method stub
        if (strategy == null) {
            return rsp[0];
        }
        return strategy.think();
    }

}

class Help implements Strategy {
    public String[] rsp = { "가위", "바위", "보" };

    public String think() {
        int num = (int) (Math.random() * 2);
        String what = this.rsp[num];
        return what;
    }
}

interface Strategy {
    public String think();
}

abstract class Player {

    // class 변수
    static protected String rsp[] = { "가위", "바위", "보" };

    // member 변수
    private String name;
    protected Strategy strategy;

    // constructor (생성자)
    protected Player(String name) { // String name은 parameter(매개 변수) argument는 전달되는 실제 값
        this.name = name;
    }

    // destructor (소멸자) 소멸자가 없는 이유 - 가비지 컬렉션을 이용해 동적으로 반환(안쓰인다 싶으면 알아서 반환)
    // @Override
    // protected void finalize() {
    // }

    // core logic
    abstract protected String nextMove(Strategy strategy);

    // getter
    public String getName() {
        return name;
    }
}

public class Play {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Student Team1 = new Student("jinsw");
        Player p = Team1;
        
        System.out.println(p.getName() + " : " + p.nextMove(new Help()));
    }
}
