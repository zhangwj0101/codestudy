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
   while(cin.getline(s,100))        //getline: ���ж�ȡ, һ�ζ�ȡ����ַ���ֱ������N������������ָ���Ľ�����(�Զ���Ļ���EOF���߻��з����������հ׷�)Ϊֹ��cin��ȡ�������������������հ׷�������ֹ��ֻ��ȡ�հ׷�֮ǰ�Ĳ���

   {
	   l=strlen(s);
	   if(islower(s[0]))            //�����ַ��Ƿ�ΪСд��ĸ ��isspace,�Ƿ�Ϊ�ո�isupper�Ƿ�ΪӢ�Ĵ�д��ĸ��isxdigit�Ƿ�Ϊ16���� 
		   s[0]-=32;                //��ĸ����ֱ�ӼӼ����֣���Ӧ��asc �뷢���仯
	   for(i=1;i<l;i++)
	   {
		   while((s[i]!=' ')&&i<l)   
			   i++;
		   while((s[i]==' ')&&i<l)  //���������еĿո���Ȼ��һ����ĸ��������ĸ
			   i++;
			if(islower(s[i])&&i<l)
				s[i]-=32;
	   }
	   puts(s);
   }
   return 0;
}