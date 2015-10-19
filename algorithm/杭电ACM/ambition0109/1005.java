////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-12 19:20:19
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:6184KB
//////////////////System Comment End//////////////////
import java.util.Scanner;


class Matrix{
	int[][] mat;
	
	Matrix(){
		mat=new int[][]{{0,0},{0,0}};
	}
	Matrix(int a,int b){
		a=a%7; b=b%7;
		mat=new int[][]{{a,b},{1,0}};
	}
	void Unit(){
		mat=new int[][]{{1,0},{0,1}};
	}
}

public class Main {
	
	static Matrix MMul(Matrix a,Matrix b){
		Matrix ans=new Matrix();
		for(int i=0;i<2;i++){
			for(int x=0;x<2;x++){
				if(b.mat[x][i]==0) continue;
				for(int y=0;y<2;y++){
					if(a.mat[i][y]==0) continue;
					ans.mat[x][y]+=a.mat[i][y]*b.mat[x][i];
					if(ans.mat[x][y]>=7){
						ans.mat[x][y]%=7;
					}
				}
			}
		}
		return ans;
	}
	
	static Matrix MPow(Matrix mat,int exp){
		Matrix ans=new Matrix(),tmp=mat;
		for(ans.Unit();exp!=0;exp>>=1){
			if((exp&1)==1) ans=MMul(ans,tmp);
			tmp=MMul(tmp,tmp);
		}
		return ans;
	}
	
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		while(true){
			int a=in.nextInt();
			int b=in.nextInt();
			int n=in.nextInt();
			if((a==0&&b==0)&&n==0) break;
			if(n==1||n==2){
				System.out.println(1);
			}else{
				Matrix ans=new Matrix(a,b);
				ans=MPow(ans,n-2);
				System.out.println((ans.mat[0][0]+ans.mat[0][1])%7);
			}
			
		}
	}
}
