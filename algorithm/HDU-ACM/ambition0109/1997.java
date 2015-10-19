////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 20:42:40
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1997
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:2996KB
//////////////////System Comment End//////////////////
import java.io.*;

public class Main {
	public static void main(String args[]) throws IOException{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(
				new InputStreamReader(System.in)));
		int[] a=new int[65];
		int[] b=new int[65];
		int[] c=new int[65];
		in.nextToken();
		int t=(int)in.nval;
		while(t--!=0){
			in.nextToken();
			int n=(int)in.nval;
			in.nextToken();
			int ta=(int)in.nval;
			for(int i=0;i<ta;i++){
				in.nextToken();
				a[i]=(int) in.nval;
			}
			in.nextToken();
			int tb=(int)in.nval;
			for(int i=0;i<tb;i++){
				in.nextToken();
				b[i]=(int) in.nval;
			}
			in.nextToken();
			int tc=(int)in.nval;
			for(int i=0;i<tc;i++){
				in.nextToken();
				c[i]=(int) in.nval;
			}
			
			boolean flag=true;
			for(int i=0;;i++){
				if(i>ta&&i>tb) break;
				if(i>ta&&i>tc) break;
				if(i>tb&&i>tc) break;
				if((i<ta&&i<tc)&&(a[i]&1)!=(c[i]&1)){
					flag=false;
					break;
				}
				if((i<ta&&i<tb)&&((a[i]&1)==(b[i]&1))){
					flag=false;
					break;
				}
			}
			System.out.println(flag?"true":"false");
		}
	}
}
