////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 20:51:18
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:7220KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	
	static boolean check(int n){
		for(int i=2;i<=Math.sqrt((double)n);i++){
			if(n%i==0) return false;
		}
		return true;
	}
	
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			int n=in.nextInt(),cnt=0;
			for(int i=0;i<n;i++){
				int num=in.nextInt();
				if(check(num)) cnt++;
			}
			System.out.println(cnt);
		}
	}
}
