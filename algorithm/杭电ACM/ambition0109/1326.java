////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 16:19:55
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1326
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:3928KB
//////////////////System Comment End//////////////////
import java.io.*;

public class Main {
	public static void main(String args[])throws IOException{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(
					new InputStreamReader(System.in)));
		int[] num=new int[55];
		int cas=0;
		while(true){
			in.nextToken();
			int t=(int)in.nval;
			if(t==0) break;
			int sum=0;
			for(int i=0;i<t;i++){
				in.nextToken();
				num[i]=(int)in.nval;
				sum+=num[i];
			}
			int avg=sum/t;
			int ans=0;
			for(int i=0;i<t;i++){
				if(num[i]>avg){
					ans+=num[i]-avg;
				}
			}
			System.out.println("Set #"+(++cas));
			System.out.println("The minimum number of moves is "+ans+".");
			System.out.println();
		}
	}
}