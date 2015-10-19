////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-10 21:47:33
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1023
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:7292KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		BigInteger[] num=new BigInteger[101];
		num[0]=BigInteger.ONE;
		num[1]=BigInteger.ONE;
		for(int i=2;i<101;i++){
			num[i]=BigInteger.ZERO;
			for(int j=0;j<i;j++){
				num[i]=num[i].add(num[j].multiply(num[i-j-1]));
			}
		}
		int n;
		while(in.hasNext()){
			n=in.nextInt();
			System.out.println(num[n]);
		}
	}
}
