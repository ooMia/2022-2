package rsp;

public abstract class Player {

    // class 변수
    static protected String rsp[] = { "가위", "바위", "보" };

    // member 변수
    private String name;
    protected Strategy strategy;

    // constructor (생성자)
    protected Player(String name) {
        this.name = name;
    }

    // destructor (소멸자)
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
