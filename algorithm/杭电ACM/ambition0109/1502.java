////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-30 14:36:55
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1502
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:11024KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;

public class Main {

	public static BigInteger[][][] dp=new BigInteger[65][65][65];

	public static BigInteger dfs(int ti,int tj,int tk){
		if(ti<tj||tj<tk) return BigInteger.ZERO;
		BigInteger Ans=new BigInteger("0");
		if(tk>0){
			if(dp[ti][tj][tk-1].equals(BigInteger.valueOf(-1))){
				dp[ti][tj][tk-1]=dfs(ti,tj,tk-1);
			}
			Ans=Ans.add(dp[ti][tj][tk-1]);
		}
		if(tj>0){
			if(dp[ti][tj-1][tk].equals(BigInteger.valueOf(-1))){
				dp[ti][tj-1][tk]=dfs(ti,tj-1,tk);
			}
			Ans=Ans.add(dp[ti][tj-1][tk]);
		}
		if(ti>0){
			if(dp[ti-1][tj][tk].equals(BigInteger.valueOf(-1))){
				dp[ti-1][tj][tk]=dfs(ti-1,tj,tk);
			}
			Ans=Ans.add(dp[ti-1][tj][tk]);
		}
		return Ans;
	}

	public static void main(String[] args){
		for(int i=0;i<=60;i++){
			for(int j=0;j<=60;j++){
				for(int k=0;k<=60;k++){
					dp[i][j][k]=BigInteger.valueOf(-1);
				}
			}
		}
		dp[1][1][1]=BigInteger.ONE;
		dp[1][1][0]=BigInteger.ONE;
		dp[1][0][0]=BigInteger.ONE;
		dp[0][0][0]=BigInteger.ZERO;
		Scanner in=new Scanner(System.in);
		int n;
		while(in.hasNextInt()){
			n=in.nextInt();
			if(dp[n][n][n].equals(BigInteger.valueOf(-1))){
				dp[n][n][n]=dfs(n,n,n);
			}
			System.out.println(dp[n][n][n]);
			System.out.println();
		}
	}

}
