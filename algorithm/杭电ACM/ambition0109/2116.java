////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-20 19:49:34
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2116
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:6300KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	
	public static void main(String arga[]){
		Scanner in=new Scanner(System.in);
		
		while(in.hasNext()){
			int n=in.nextInt();
			BigInteger tmp=BigInteger.ONE;
			BigInteger a=in.nextBigInteger();
			BigInteger b=in.nextBigInteger();
			BigInteger sum=a.add(b);
			tmp=tmp.shiftLeft(n-1);
			if(sum.compareTo(BigInteger.ZERO)>=0){
				sum=sum.add(BigInteger.ONE);
			}else{
				sum=sum.abs();
			}
		//	System.out.println(sum+"  "+tmp);
			if(sum.compareTo(tmp)>0){
				System.out.println("Yes");
			}else{
				System.out.println("WaHaHa");
			}
		}
	}
}
