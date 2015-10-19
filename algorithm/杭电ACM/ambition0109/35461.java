////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-26 12:02:01
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 3546
////Problem Title: 
////Run result: Accept
////Run time:1828MS
////Run memory:7468KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger[] Num=new BigInteger[10];
		Arrays.fill(Num,BigInteger.ONE);
		String cmd;
		while(in.hasNext()){
			cmd=in.next();
			if(cmd.charAt(1)=='='){
				int s1=(int)cmd.charAt(0)-(int)'A';
				int s2=(int)cmd.charAt(2)-(int)'A';
				Num[s1]=Num[s2];
			}else if(cmd.charAt(1)=='+'){
				int s1=(int)cmd.charAt(0)-(int)'A';
				int s2=(int)cmd.charAt(3)-(int)'A';
				Num[s1]=Num[s1].add(Num[s2]);
			}else{
				int s1=(int)cmd.charAt(0)-(int)'A';
				int s2=(int)cmd.charAt(3)-(int)'A';
				Num[s1]=Num[s1].multiply(Num[s2]);
			}
		}
		for(int i=0;i<10;i++){
			System.out.println(Num[i]);
		}
	} 
}
