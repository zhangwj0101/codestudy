////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-26 11:54:08
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 3546
////Problem Title: 
////Run result: Accept
////Run time:1890MS
////Run memory:7464KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger[] Num=new BigInteger[10];
		for(int i=0;i<10;i++){
			Num[i]=BigInteger.ONE;
		}
		String cmd;
		while(in.hasNext()){
			cmd=in.next();
//			if(Pattern.matches("[A-J]=[A-J]",cmd)){
			if(cmd.charAt(1)=='='){
				int s1=(int)cmd.charAt(0)-(int)'A';
				int s2=(int)cmd.charAt(2)-(int)'A';
				Num[s1]=Num[s2];
			}else if(cmd.charAt(1)=='+'){
//			}else if(Pattern.matches("[A-J][+]=[A-J]",cmd)){
				int s1=(int)cmd.charAt(0)-(int)'A';
				int s2=(int)cmd.charAt(3)-(int)'A';
				Num[s1]=Num[s1].add(Num[s2]);
			}else{
//			}else if(Pattern.matches("[A-J][*]=[A-J]",cmd)){
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
