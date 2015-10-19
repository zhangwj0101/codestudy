////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-10 22:36:48
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2104
////Problem Title: 
////Run result: Accept
////Run time:1203MS
////Run memory:7308KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	
	static int GCD(int a,int b){
		while(b!=0){
			int t=b;
			b=a%b;
			a=t;
		}
		return a;
	}
	
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(true){
			int n=in.nextInt();
			int m=in.nextInt();
			if(n==-1||m==-1) break;
			if(n<m){
				int t=n; n=m; m=t;
			}
			System.out.println(GCD(n,m)==1?"YES":"POOR Haha");
		}
	}
}
