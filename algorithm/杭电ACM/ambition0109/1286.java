////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 21:19:47
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1286
////Problem Title: 
////Run result: Accept
////Run time:1562MS
////Run memory:7136KB
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
		int t=in.nextInt();
		while(t--!=0){
			int n=in.nextInt();
			int cnt=0;
			for(int i=1;i<n;i++){
				if(GCD(n,i)==1) cnt++;
			}
			System.out.println(cnt);
		}
	}
}
