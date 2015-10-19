////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-11 00:13:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int l,i;
	char s[100];
   while(cin.getline(s,100))        //getline: 按行读取, 一次读取多个字符，直到读满N个，或者遇到指定的结束符(自定义的或者EOF或者换行符，不包括空白符)为止。cin读取，遇到结束符（包括空白符）会终止，只读取空白符之前的部分

   {
	   l=strlen(s);
	   if(islower(s[0]))            //测试字符是否为小写字母 ，isspace,是否为空格，isupper是否为英文大写字母，isxdigit是否为16进制 
		   s[0]-=32;                //字母可以直接加减数字，对应的asc 码发生变化
	   for(i=1;i<l;i++)
	   {
		   while((s[i]!=' ')&&i<l)   
			   i++;
		   while((s[i]==' ')&&i<l)  //遍历完所有的空格自然下一个字母便是首字母
			   i++;
			if(islower(s[i])&&i<l)
				s[i]-=32;
	   }
	   puts(s);
   }
   return 0;
}