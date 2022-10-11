package Team2;

public abstract class Player {//구체화돼야함

    // class 변수
    static protected String rsp[] = { "가위", "바위", "보" };//static은 클래스에 할당하는 무언가를 하고싶을 때 사용(공통으로 갖고있는)

    // member 변수
    private String name;
    protected Strategy strategy;//protected는 상속관계에서 사용가능

    // constructor (생성자)
    protected Player(String name) {//인자(실제로 넘겨주는 애)vs매개변수(가상으로 넘겨주는 애,String name)
        this.name = name;
    }

    // destructor (소멸자)//소멸자 없는 이유:자바 언어는 가비지 콜렉션을 통해 동적으로 할당/반환을 해주기 때문에 소멸자를 굳이 안넣어도 안쓰면 알아서 정리해줌
    // @Override
    // protected void finalize() {
    // }

    // core logic
    abstract protected String nextMove(Strategy strategy);//strategyA/B에 따라 nextMove가 다르게 구현됨

    // getter
    public String getName() {
        return name;
    }
}
