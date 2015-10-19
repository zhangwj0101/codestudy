////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 22:20:42
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1568
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:7144KB
//////////////////System Comment End//////////////////
import java.util.Scanner;

public class Main {
	static int[] Fib=new int[]{0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765};
	static public void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			int n=in.nextInt();
			if(n<21){
				System.out.println(Fib[n]);
			}else{
				double ff=-0.5*(Math.log10(5.0))+n*Math.log10((Math.sqrt(5.0)+1.0)/2.0);
				ff=Math.pow(10,(double)(ff-(int)ff));
				while(ff<1000) ff*=10;
				System.out.println((int)ff);
			}
		}
	} 
}
