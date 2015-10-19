////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 20:44:57
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:6096KB
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
		while(in.hasNext()){
			int a=in.nextInt();
			int b=in.nextInt();
			if(b>a){
				int t=b; b=a; a=t;
			}
			int gcd=GCD(a,b);
			System.out.println((a*b/gcd));
		}
	}
}
