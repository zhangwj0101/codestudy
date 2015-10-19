////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 20:03:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2687
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:156KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

struct Matrix {
    int Mat[11][11];
};

Matrix Get(Matrix& Mat, int k, int n) {
    Matrix Sum(Mat);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Sum.Mat[i][j] += Mat.Mat[j][n - i - 1];
            Sum.Mat[i][j] += Mat.Mat[n - i - 1][n - j - 1];
            Sum.Mat[i][j] += Mat.Mat[n - j - 1][i];
            Sum.Mat[i][j] *= k;
        }
    }
    return Sum;
}

Matrix Mat, Ans;

int main() {
    int n;
    while (scanf("%d", &n)!=EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &Mat.Mat[i][j]);
            }
        }
        int p;
        scanf("%d", &p);
        p += 1;
        Ans = Get(Mat, p / 4, n);
        if (p % 4) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    Ans.Mat[i][j] += Mat.Mat[i][j];
                    if (p % 4 > 1) Ans.Mat[i][j] += Mat.Mat[n - j - 1][i];
                    if (p % 4 > 2) Ans.Mat[i][j] += Mat.Mat[n - i - 1][n - j - 1];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d", Ans.Mat[i][0]);
            for (int j = 1; j < n; j++) {
                printf(" %d", Ans.Mat[i][j]);
            }
            printf("\n");
        }
    }
}