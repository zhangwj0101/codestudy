////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 22:27:36
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:6072KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	static public void main(String args[]){
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		while(t--!=0){
			int n=in.nextInt();
			double ans=0.0;
			for(int i=1;i<=n;i++){
				ans+=Math.log10((double)i);
			}
			System.out.println(((int)ans+1));
		}
	} 
}
