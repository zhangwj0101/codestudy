////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 19:49:44
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:6040KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(true){
			String str=in.next();
			if(str.equals("0")) break;
			int ans=0;
			for(int i=0;i<str.length();i++){
				int tmp=ans+str.charAt(i)-'0';
				tmp=tmp/10+tmp%10;
				ans=tmp;
			}
			System.out.println(ans);
		}
	}
}
