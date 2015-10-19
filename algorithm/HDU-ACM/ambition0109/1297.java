////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-30 15:56:41
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:7652KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args){
		BigInteger[] num=new BigInteger[1005];
		num[0]=BigInteger.ONE;
		num[1]=BigInteger.ONE;
		num[2]=BigInteger.valueOf(2);
		num[3]=BigInteger.valueOf(4);
		for(int i=4;i<=1000;i++){
			num[i]=num[i-4];
			num[i]=num[i].add(num[i-2]);
			num[i]=num[i].add(num[i-1]);
		}
		Scanner in=new Scanner(System.in);
		int n;
		while(in.hasNextInt()){
			n=in.nextInt();
			System.out.println(num[n]);
		}
	}
}
