package src;

public abstract class Player {

    // class 변수
    static protected String rsp[] = { "가위", "바위", "보" };

    // member 변수
    protected String name;
    protected Strategy strategy;

    // constructor (생성자)
    protected Player() {
    }

    protected Player(String name) {
        this.name = name;
    }

    // destructor (소멸자)
    // @Override
    // protected void finalize() {
    // }

    // core logic
    abstract public String nextMove(Strategy strategy);

    // getter
    public String getName() {
        return name;
    }
}