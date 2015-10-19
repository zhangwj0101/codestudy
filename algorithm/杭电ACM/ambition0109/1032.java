////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 20:01:35
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:6116KB
//////////////////System Comment End//////////////////
import java.util.Scanner;


public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			int l=in.nextInt();
			int r=in.nextInt();
			int ll=l,rr=r;
			if(ll>rr){
				int t=ll; ll=rr; rr=t;
			}
			int ans=0;
			for(int i=ll;i<=rr;i++){
				int cnt=1;
				for(int t=i;t!=1;cnt++){
					if((t&1)==1){
						t=t*3+1;
					}else{
						t=t/2;
					}
				}
				if(cnt>ans) ans=cnt;
			}
			System.out.println(l+" "+r+" "+ans);
		}
	}
}
