////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-10 20:17:11
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1092
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:6096KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(true){
			int n=in.nextInt(),ans=0;
			if(n==0) break;
			for(int i=0;i<n;i++){
				int t=in.nextInt();
				ans+=t;
			}
			System.out.println(ans);
		}
	}
}
