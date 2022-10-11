package Team2;

//public class Game implements Startegy{ // 오타!!
public class Game implements Strategy{
//	public String think(){ // return type 변경해야해!
	public int think() {
		//리턴을 인트로(인덱스)
		//student.nextmove=?가위/바위/보===>이거를 인덱스를 전달을 think에
		//랜덤을 할지,직접 입력할지 정하가..?
		int n;
		n=(int)(Math.random()*3);//0~2까지
		return n;//0,1,2 중에

	}
}
