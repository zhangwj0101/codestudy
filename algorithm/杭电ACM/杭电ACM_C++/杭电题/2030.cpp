////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-05 17:25:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()                //汉字机内码在计算机的表达方式的描述是,使用二个字节，每个字节最高位一位为1. 
                          //计算机中,补码第一位是符号位,1 表示为负数,所以 汉字机内码的每个字节表示的十进制数都是负数　　
                          //所以这题也就可以简化为输入字符串判断其中字符转化为十进制数是否小于零.
                          //注意:汉字是有两个小于零的字符组成,所以在统计结果的时候就要将count除以2了
{
	int i,j,l,sum;        //比如“嗨”、“！”、“。”，汉字及中文标点就是双字节字符；“k”、“!”、“.”，英文字母及英文标点是单字节的。
	char s[200],n[2];
	cin.getline(n,80);
	for(i=0;i<*n-'0';i++)
	{
		cin.getline(s,200);
		l=strlen(s);
		for(sum=0,j=0;j<l;j++)
			if(s[j]<0)
				sum++;
		cout<<sum/2<<endl;
	}
   return 0;
}