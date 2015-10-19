////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 21:39:56
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1130
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:7176KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		BigInteger[] ans=new BigInteger[105];
		ans[0]=BigInteger.ONE;
		ans[1]=BigInteger.ONE;
		ans[3]=BigInteger.valueOf(5);
		for(int i=2;i<=100;i++){
			if(i==3) continue;
			ans[i]=BigInteger.ZERO;
			for(int j=0;j<i;j++){
				ans[i]=ans[i].add(ans[j].multiply(ans[i-j-1]));
			}
		}
		
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			int n=in.nextInt();
			System.out.println(ans[n]);
		}
	}
}
