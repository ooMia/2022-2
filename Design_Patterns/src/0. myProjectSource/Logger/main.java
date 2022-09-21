public class main {
    public static void main(String[] args) {

        User[] users = new User[10];
        for (int i=0; i<10;i++){
            users[i] = new User("hyeon-hak"+i);
            users[i].start();
        }






//        Account acct1 = new Account("hyeonhak1", 1000);
//        acct1.deposit(200);
//        Account acct2 = new Account("hyeonhak2", 2000);
//        acct2.withdraw(30);


        // 첫 번째 방법: p2.print 대신 p1.print 쓰기
        // 두 번째 방법: p2를 새로 생성하는 대신 p2 = p1으로 대체하기
        // 위 방법의 한계점:
        // 1. p1이 생성되기 전(p1 == null)이라면 문제가 됨 >> 조건문으로 확인 후 생성하면 해결됨
        // 2. 애초에 p1이라는 변수의 존재를 모르는 경우 문제가 됨
        //      p1이라고 명명된 사실을 모르는 경우 정도는 양호하고,
        //      한 번 생성된 객체는 즉각 폐기(재사용 불가)되는 등의 제약도 존재 가능

    }

}
