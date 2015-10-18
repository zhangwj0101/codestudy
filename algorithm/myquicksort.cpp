#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LEN 3

void swap(int *a,int *b){
	int t  = *a;
	*a = *b;
	*b = t;
}


void rotate(int a[],int s,int len){

	if(s+1 == len){
		for(int  i = 0;i < len;i++){
			printf("%d ",a[i]);
		}
		puts("\n");
		return ;
	}
	rotate(a,s+1,len);

	for(int  j = s+1;j < len;j++){
		swap(a+s,a+j);
		rotate(a,s+1,len);
		swap(a+j,a+s);
	}

}

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	int *a = new int[LEN];
	freopen("out.txt","w",stdout);
	for(int i = 0;i < LEN;i++){
		a[i] = i+1;
	}
	rotate(a,0,LEN);
	return 0;
}
