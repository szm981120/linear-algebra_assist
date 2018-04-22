#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 10
void CramerRule()
{
    int matrix[M][M],m1[M][M],constant[M],D[M];//方程的系数矩阵 中间计算矩阵 常数项 存放D1D2...Dn的数组
    double result[M];
    int row,column;//行 列
    int i,j,k,l;
    int n;
    char ch,enter;
    printf("|-------------------------------------------|\n");
    printf("   This is a calculator to solve equations by the Cramer's rule\n\n");
    printf("The form of equation is as follows:\n");
    printf("   a11X1 + a12X2 + ...... + a1nXn = b1\n");
    printf("   a21X1 + a22X2 + ...... + a2nXn = b2\n");
    printf("   ......          ......       ......\n");
    printf("   an1X1 + an2X2 + ...... + annXn = bn\n");
    printf("NOTICE: The number of unknowns and equations should be consistent\n");
    printf("^_^Please input the number of unknowns or equations:");
    scanf("%d",&n);
    printf("^_^Please input the the coefficient of equation:\n");//输入方程的系数
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    D[0] = Deter_minant(matrix, n);
    if(D[0]==0)
    {
        printf("The coefficient matrix is irreversible, so it can't give a unique solution.\n");
        return 0;
    }
    else
    {
        printf("^_^Please input %d constant term of the equation.\n", n);
        for(l=0;l<n;l++)
        {
            scanf("%d", &constant[l]);
        }
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    m1[i][j] = matrix[i][j];
                }
            }
            for(l=0;l<n;l++)
            {
                m1[l][k] = constant[l];
            }
            D[1+k] = Deter_minant(m1, n);
        }
        printf("\n^_^The result is as follows:\n");
        for(k=0;k<n;k++)
        {
            result[k] = (double)D[1+k]/D[0];
            printf("x%d = %lf\t", k+1, result[k]);
        }

    }
    printf("\n\n|-------------------------------------------|\n");
    printf("Please press enter to exit.");
    while((ch=getchar())!='\n');
    scanf("%c",&enter);
    printf("%c",enter);
    return 0;
}
