////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-26 20:33:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3575
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:160KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define FOR(n) for(int II = 0 ; II < n ; II++)

int main() {
    int T, c, in, out, pos;
    char row[3][1500], clum[2][1500];
    int len;
    //freopen ("in.txt", "r", stdin) ;

    scanf("%d", &T);
    getchar();
    for (int c = 1; c <= T; c++) {
        printf("Case %d:\n", c);
        scanf("%d%d", &in, &out);
        getchar();
        memset(row, 0, sizeof (row));
        memset(clum, 0, sizeof (clum));

        gets(row[0]);
        len = strlen(row[0]);
        FOR(in)
        gets(clum[0]);
        gets(row[1]);
        FOR(in)
        gets(clum[1]);
        gets(row[2]);

        //output

        //first row
        pos = 1;
        while (1) {

            printf(" ");
            for (int JJ = 0; JJ < out; JJ++)
                printf("%c", row[0][pos]);
            printf(" ");
            pos += (in + 3);
            if (pos > len) break;
            printf(" ");
        }
        printf("\n");

        FOR(out) {
            pos = 0;
            while (1) {
                printf("%c", clum[0][pos]);
                for (int KK = 0; KK < out; KK++)
                    printf(" ");
                printf("%c", clum[0][pos + in + 1]);
                pos += in + 3;
                if (pos > len) break;
                 printf(" ");
            }
            printf("\n");
        }



        //mid row
        pos = 1;
        while (1) {

            printf(" ");
            for (int JJ = 0; JJ < out; JJ++)
                printf("%c", row[1][pos]);
            printf(" ");
            pos += (in + 3);
            if (pos > len) break;
            printf(" ");
        }
        printf("\n");

        FOR(out) {
            pos = 0;
            while (1) {
                printf("%c", clum[1][pos]);
                for (int KK = 0; KK < out; KK++)
                    printf(" ");
                printf("%c", clum[1][pos + in + 1]);
                
                pos += in + 3;
                if (pos > len) break;
                printf(" ");
            }
            printf("\n");
        }
        //last row
        pos = 1;
        while (1) {

            printf(" ");
            for (int JJ = 0; JJ < out; JJ++)
                printf("%c", row[2][pos]);
            printf(" ");
            pos += (in + 3);
            if (pos > len) break;
            printf(" ");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}