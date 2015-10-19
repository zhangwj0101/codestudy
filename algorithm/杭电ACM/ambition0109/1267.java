////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 22:29:18
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1267
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:7368KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		BigInteger[][] num=new BigInteger[105][105];
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
		
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			int n=in.nextInt();
			int m=in.nextInt();
			System.out.println(num[n][m]);
		}
		
	}
}
