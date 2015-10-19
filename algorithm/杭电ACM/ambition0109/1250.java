////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-25 21:15:29
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:11052KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static public void main(String[] args){
		
		BigInteger[] Fib=new BigInteger[7500];
		Fib[1]=BigInteger.ONE;
		Fib[2]=BigInteger.ONE;
		Fib[3]=BigInteger.ONE;
		Fib[4]=BigInteger.ONE;
		for(int i=5;i<7500;i++){
			Fib[i]=Fib[i-1];
			Fib[i]=Fib[i].add(Fib[i-2]);
			Fib[i]=Fib[i].add(Fib[i-3]);
			Fib[i]=Fib[i].add(Fib[i-4]);
		}
		
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			int n=in.nextInt();
			System.out.println(Fib[n]);
//			System.out.println(Fib[n].toString().length());
		}
	}
}
