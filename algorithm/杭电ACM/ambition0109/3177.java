////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 17:27:26
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 3177
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:3696KB
//////////////////System Comment End//////////////////
import java.io.*;
import java.util.Arrays;

@SuppressWarnings("rawtypes")
class Node implements Comparable{
	int a,b,dif;
	
	Node(int a,int b){
		this.a=a;
		this.b=b;
		this.dif=b-a;
	}
	
	@Override
	public int compareTo(Object arg0){
		int dif=((Node)arg0).dif;
		return dif-this.dif;
	}
}

public class Main {
	public static void main(String args[]) throws IOException{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		Node[] node=new Node[1005];
		in.nextToken();
		int t=(int)in.nval;
		while(t--!=0){
			in.nextToken();
			int v=(int)in.nval;
			in.nextToken();
			int n=(int)in.nval;
			for(int i=0;i<n;i++){
				in.nextToken();
				int a=(int)in.nval;
				in.nextToken();
				int b=(int)in.nval;
				node[i]=new Node(a,b);
			}
			Arrays.sort(node,0,n);
			boolean flag=true;
			for(int i=0;i<n;i++){
				if(node[i].b>v){
					flag=false;
					break;
				}
				v-=node[i].a;
			}
			System.out.println(flag?"Yes":"No");
		}
	}
}
