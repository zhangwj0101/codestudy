////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-31 10:41:31
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:6284KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		while(t--!=0){
			BigInteger Sum=BigInteger.valueOf(0);
			BigInteger num=in.nextBigInteger();
			while(!num.equals(BigInteger.ZERO)){
				Sum=Sum.add(num);
				num=in.nextBigInteger();
			}
			System.out.println(Sum);
			if(t!=0){
				System.out.println();
			}
		}
	}
}
