////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-30 16:43:37
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:6748KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigDecimal a,b;
		while(in.hasNext()){
			a=in.nextBigDecimal();
			b=in.nextBigDecimal();
			System.out.println(a.add(b).stripTrailingZeros().toPlainString());
		}
	}
}
