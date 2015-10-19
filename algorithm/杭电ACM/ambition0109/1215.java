////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 21:07:40
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:984MS
////Run memory:9192KB
//////////////////System Comment End//////////////////
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int[] num=new int[500005];
		Arrays.fill(num,0);
		for(int i=1;i<500000;i++){
			for(int j=i+i;j<=500000;j+=i){
				num[j]+=i;
			}
		}
		
		int t=in.nextInt();
		while(t--!=0){
			int n=in.nextInt();
			System.out.println(num[n]);
		}
	}
}
