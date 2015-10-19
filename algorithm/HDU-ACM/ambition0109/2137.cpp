////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 20:18:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
int times(int n)
{
    n%=8;
    if(n<0)
        n+=8;
    return n;//����������Ҫ��ת�Ĵ����������������ᵽ0-7
}//û�д��������壬��Ŀû˵�����Ҫ�࿼�Ǹ�����Ҳ����clockwise��
void Circumgyrate(char *a,int n)
{
    int len=strlen(a),i;
    switch(n)
    {
    case 0:
        {
            puts(a);
            break;
        }
    case 1:
        {
            for(i=len-1;i>=0;i--)
                printf("%*c\n",i+1,a[i]);
            break;
        }
    case 2:
        {
            for(i=len-1;i>=0;i--)
                printf("%*c\n",(len>>1)+1,a[i]);
            break;
        }
    case 3:
        {
            for(i=len-1;i>=0;i--)
                printf("%*c\n",len-i,a[i]);
            break;
        }
    case 4:
        {
            for(i=len-1;i>=0;i--)
                printf("%c",a[i]);
            printf("\n");
            break;
        }
    case 5:
        {
            for(i=0;i<len;i++)
                printf("%*c\n",len-i,a[i]);
            break;
        }
    case 6:
        {
            for(i=0;i<len;i++)
                printf("%*c\n",(len>>1)+1,a[i]);
            break;
        }
    case 7:
        {
            for(i=0;i<len;i++)
                printf("%*c\n",i+1,a[i]);
            break;
        }
    }
}//�������ӡ��ûʲô����Ҫ���Ǹ���*�ŵģ�����ʹ�������i�仯�����Ƕ�Ӹ�������Ϊ����
int main()
{
    char a[90];
    int n;
    while(scanf("%s",a)==1)
    {
        scanf("%d",&n);
        Circumgyrate(a,times(n));
    }
    return 0;
}
//Accepted 2137 31MS 0K 1025 B C++