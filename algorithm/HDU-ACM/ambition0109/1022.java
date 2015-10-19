////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-10 21:36:24
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1022
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:6700KB
//////////////////System Comment End//////////////////
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;


public class Main {
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(in.hasNext()){
			Stack<Character> stk=new Stack<Character>();
			LinkedList<Boolean> que=new LinkedList<Boolean>();
			int n=in.nextInt();
			String before=in.next();
			String after=in.next();
			int i=0,j=0;
			while(true){
				if(!stk.empty()&&after.charAt(j)==stk.peek()){
					stk.pop(); j++;
					que.add(false);
				}else if(i<n&&j<n&&before.charAt(i)==after.charAt(j)){
					i++;j++;
					que.add(true);
					que.add(false);
				}else if(i<n){
					stk.push(before.charAt(i++));
					que.add(true);
				}else{
					break;
				}
			}
			if(j!=n){
				System.out.println("No.");
			}else{
				System.out.println("Yes.");
				while(!que.isEmpty()){
					if(que.pop()) System.out.println("in");
					else System.out.println("out");
				}
			}
			System.out.println("FINISH");
		}
	}
}
