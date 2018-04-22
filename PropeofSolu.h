#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 10

void PropeofSolu()
{
    int coefmatrix[M][M], augmatrix[M][M];//系数矩阵 增广矩阵
    int row, column;
    int rank1, rank2;
    int i,j,k;
    int flag = 1;
    char ch,enter;
    printf("|-------------------------------------------|\n");
    printf("   This is a calculator to consider the properties of solutions of linear equations\n\n");
    printf("^_^Please input the number of equations and unknowns:");
    scanf("%d%d", &row, &column);
    printf("^_^Please input the the coefficient of equation:\n");//输入方程的系数
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&coefmatrix[i][j]);
        }
    }
    printf("^_^Please input %d constant term of the equation.\n", row);
    printf("NOTICE:If it's a linear homogeneous equation, please input %d 0.", row);
    for(k=0;k<row;k++)
    {
        scanf("%d", &augmatrix[k][column]);
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            augmatrix[i][j] = coefmatrix[i][j];
        }
    }
    rank1 = Matri_cialRank(coefmatrix, row ,column);
    rank2 = Matri_cialRank(augmatrix, row ,column+1);
    for(k=0;k<row;k++)
    {
        if(augmatrix[k][column]!=0)
        {
            flag = 0;
            break;
        }
    }
    if(flag==1)
    {
        printf("What you have entered is a linear homogeneous equation set.\n");//齐次线型方程组
        if(rank1==column)
            printf("There is a unique solution for the equation set.\n");//有特解
        else
            printf("There is a general solution of the equation set.\n");//有通解
    }
    else
    {
        printf("What you have entered is a linear nonhomogeneous equation set.\n");//你输入的是一个非齐次线性方程组
        if(rank1!=rank2)
            printf("There is no solution to the equation set.\n");//无解
        else
        {
            if(rank1==column)
                printf("There is a unique solution for the equation set.\n");//有特解
            else
                printf("There is a general solution of the equation set.\n");//有通解
        }
    }
    printf("\n\n|-------------------------------------------|\n");
    printf("Please press enter to exit.");
    while((ch=getchar())!='\n');
    scanf("%c",&enter);
    printf("%c",enter);
    return 0;
}
