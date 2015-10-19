////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-30 19:12:37
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1063
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:7900KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
	static BigDecimal myPow(BigDecimal num,int pow){
		BigDecimal tmp=num,Ans=BigDecimal.ONE;
		for(;pow!=0;pow>>=1){
			if((pow&1)!=0) Ans=Ans.multiply(tmp);
			tmp=tmp.multiply(tmp);
		}
		return Ans;
	}
	
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigDecimal num;
		int p;
		while(in.hasNext()){
			num=in.nextBigDecimal();
			p=in.nextInt();
			num=myPow(num,p);
			String Ans=num.stripTrailingZeros().toPlainString();
			if(num.doubleValue()<1) Ans=Ans.substring(1);
			System.out.println(Ans);
		}
	}
}
