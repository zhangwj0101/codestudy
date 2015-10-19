////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-10 21:26:48
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:3664KB
//////////////////System Comment End//////////////////
import java.io.*;

public class Main {
	public static void main(String args[])throws IOException{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		while(true){
			in.nextToken();
			int n=(int)in.nval;
			if(n==0) break;
			int ans=0;
			for(int i=0;i<n;i++){
				in.nextToken();
				int tmp=(int)in.nval;
				ans^=tmp;
			}
			System.out.println(ans);
		}
	}
}
