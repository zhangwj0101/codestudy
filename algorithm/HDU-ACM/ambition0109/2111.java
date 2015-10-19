////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 17:04:52
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2111
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:6816KB
//////////////////System Comment End//////////////////
import java.util.Arrays;
import java.util.Scanner;

@SuppressWarnings("rawtypes")
class Node implements Comparable {
	int p,m;
	Node(int p,int m){
		this.p=p;
		this.m=m;
	}
	
	@Override
	public int compareTo(Object arg0){
		int p=((Node)arg0).p;
		return p-this.p;
	}
}

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		Node[] node=new Node[105];
		while(true){
			int v=in.nextInt();
			if(v==0) break;
			int n=in.nextInt();
			for(int i=0;i<n;i++){
				int p=in.nextInt();
				int m=in.nextInt();
				node[i]=new Node(p,m);
			}
			Arrays.sort(node,0,n);
			int ans=0,i;
			for(i=0;i<n;i++){
				if(v>node[i].m){
					v-=node[i].m;
					ans+=node[i].p*node[i].m;
				}else break;
			}
			if(i!=n) ans+=node[i].p*v;
			System.out.println(ans);
		}
	}
}
