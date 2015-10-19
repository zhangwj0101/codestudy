////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 21:29:11
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:6196KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		while(t--!=0){
			int n=in.nextInt();
			double g=n*Math.log10((double)n);
			g=g-(long)g;
			double h=Math.pow(10.0,g);
			System.out.println(((int)h));
		}
	}
}
