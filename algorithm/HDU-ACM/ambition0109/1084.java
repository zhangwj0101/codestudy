////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 20:39:12
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1084
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:7048KB
//////////////////System Comment End//////////////////
import java.util.Arrays;
import java.util.Scanner;

@SuppressWarnings("rawtypes")
class Node implements Comparable{
	String time;
	int score,pos;
	
	Node(String t,int i){
		this.time=t;
		this.pos=i;
	}
	
	public int compareTo(Object arg0){
		String t=((Node)arg0).time;
		return this.time.compareTo(t);
	}
	
	public String toString(){
		return (""+score);
	}
}

public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		Node[][] time=new Node[6][];
		int[] num=new int[6];
		int[] pos=new int[105];

		while(true){
			for(int i=0;i<6;i++){
				time[i]=new Node[105];
				num[i]=0;
			}
			int n=in.nextInt();
			if(n<0) break;
			for(int i=0;i<n;i++){
				int t=in.nextInt();
				String str=in.next();
				time[t][num[t]++]=new Node(str,i);
				pos[i]=t;
			}

			for(int i=0;i<num[0];i++) time[0][i].score=50;
			for(int i=0;i<num[5];i++) time[5][i].score=100;
			for(int i=1;i<5;i++){
				if(num[i]==0) continue;
				Arrays.sort(time[i],0,num[i]);
				int j=0;
				for(j=0;j<num[i]/2;j++){
					time[i][j].score=i*10+55;
				}
				for(;j<num[i];j++){
					time[i][j].score=i*10+50;
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<num[pos[i]];j++){
					if(time[pos[i]][j].pos==i){
						System.out.println(time[pos[i]][j]);
					}
				}
			}
			System.out.println();
		}
	}
}
