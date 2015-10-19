////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 22:15:31
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1133
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:8304KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		BigInteger[][] num=new BigInteger[105][105];
		BigInteger[] fact=new BigInteger[105];
		for(int i=0;i<=100;i++){
			if(i==0) fact[0]=BigInteger.ONE;
			else fact[i]=fact[i-1].multiply(BigInteger.valueOf(i));
		}
		for(int i=0;i<=100;i++){
			for(int j=0;j<=100;j++){
				if(j<=i){
					if(i==0) num[i][j]=BigInteger.ZERO;
					else if(j==0) num[i][j]=BigInteger.ONE;
					else num[i][j]=num[i-1][j].add(num[i][j-1]);
				}else{
					num[i][j]=BigInteger.ZERO;
				}

			}
		}
		
		for(int i=0;i<=100;i++){
			for(int j=0;j<=i;j++){
				num[i][j]=num[i][j].multiply(fact[i]);
				num[i][j]=num[i][j].multiply(fact[j]);
			}
		}
		
		Scanner in=new Scanner(System.in);
		int cas=0;
		while(true){
			int n=in.nextInt();
			int m=in.nextInt();
			if(n==0&&m==0) break;
			System.out.println("Test #"+(++cas)+":");
			System.out.println(num[n][m]);
		}
		
	}
}
