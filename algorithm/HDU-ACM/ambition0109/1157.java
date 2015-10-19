////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 16:34:06
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:3648KB
//////////////////System Comment End//////////////////
import java.io.*;
import java.util.Arrays;


public class Main {
	public static void main(String args[])throws IOException{
		StreamTokenizer in=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int[] num=new int[10000];
		while(in.nextToken()!=StreamTokenizer.TT_EOF){
			int n=(int)in.nval;
			for(int i=0;i<n;i++){
				in.nextToken();
				num[i]=(int)in.nval;
			}
			Arrays.sort(num,0,n);
			System.out.println(num[n/2]);
		}
	}
}
