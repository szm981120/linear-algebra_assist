#include <stdio.h>
#include <stdlib.h>
#define MulM 10
int calculation(int matrix1[][MulM],int matrix2[][MulM],int i,int j,int column)
{
    int sum=0,k;
    for(k=0;k<column;k++)
    {
        sum = sum+matrix1[i][k]*matrix2[k][j];
    }
    return sum;
}
void MatrixMul()
{
    int matrix1[MulM][MulM],matrix2[MulM][MulM],result[MulM][MulM];
    int row,column;
    int i,j;
    char ch,enter;
    printf("|-------------------------------------------|\n");
    printf("   This is a matrix multiplication calculator.\n\n");
    printf("^_^Please input the row and the column of the first matrix:");
    scanf("%d %d",&row,&column);
    printf("^_^Please input the elements of the first matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("\n^_^Please input the elements of the second matrix:\n  (Notice:the second matrix's size is %d*%d)\n",column,row);
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++)
        {
            result[i][j] = calculation(matrix1,matrix2,i,j,column);
        }
    }
    printf("\n^_^The result is as follows:\n");
    for(i=0;i<row;i++)
    {
        printf("|");
        for(j=0;j<row;j++)
        {
            printf("%5d",result[i][j]);
        }
        printf("  |");
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
    printf("Please press enter to exit.");
    while((ch=getchar())!='\n');
    scanf("%c",&enter);
    printf("%c",enter);
    return;
}

