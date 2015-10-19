////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-31 10:29:18
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1316
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:7024KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger a,b;
		while(true){
			a=in.nextBigInteger();
			b=in.nextBigInteger();
			if(a.equals(BigInteger.ZERO)&&b.equals(BigInteger.ZERO)){
				break;
			}
			BigInteger fib,tmp;
			tmp=BigInteger.ONE;
			fib=BigInteger.ONE;
			int cnt=0;
			while(true){
				if(fib.compareTo(a)>=0&&fib.compareTo(b)<=0){
					cnt++;
				}else if(fib.compareTo(b)>0){
					break;
				}
				BigInteger ttmp=fib;
				fib=fib.add(tmp);
				tmp=ttmp;
			}
			System.out.println(cnt);
		}
	}
}
