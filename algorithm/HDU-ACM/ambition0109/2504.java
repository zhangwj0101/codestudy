////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 21:00:19
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2504
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:6256KB
//////////////////System Comment End//////////////////
import java.util.Scanner;


public class Main {
	
	static int GCD(int a,int b){
		if(a<b){
			int t=a; a=b; b=t;
		}
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
			int a=in.nextInt();
			int b=in.nextInt();
			for(int i=b+b;;i+=b){
				if(GCD(i,a)==b){
					System.out.println(i);
					break;
				}
			}
		}
	}
}
