////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 21:23:00
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1443
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:7132KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int[] ans=new int[]{0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
		while(true){
			int n=in.nextInt();
			if(n==0) break;
			System.out.println(ans[n]);
		}
	}
}
