#include <stdio.h>
#include <stdlib.h>
#define MulM 15
int calculation(int matrix1[][MulM],int matrix2[][MulM],int i,int j,int column1)
{
    int sum=0,k;
    for(k=0;k<column1;k++){
        sum = sum + matrix1[i][k]*matrix2[k][j];
    }
    return sum;
}
void MatrixMul()
{
    int matrix1[MulM][MulM],matrix2[MulM][MulM],result[MulM][MulM];
    int row1,column1,row2,column2;
    int i,j;
    char ch,enter;
    printf("|-------------------------------------------|\n");
    printf("   This is a matrix multiplication calculator.\n\n");
    printf("^_^Please input the row and the column of the first matrix:");
    scanf("%d %d",&row1,&column1);
    getchar();
    printf("^_^Please input the row and the column of the second matrix:");
    scanf("%d%d",&row2,&column2);
    while(column1!=row2){
        printf("The column of the first is not equal to the row of the second!\n");
        printf("You have to input the row and the column of the second matrix AGAIN!");
        getchar();
        scanf("%d%d",&row2,&column2);
    }
    printf("^_^Please input the elements of the first matrix:\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<column1;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("\n^_^Please input the elements of the second matrix:\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<column2;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    for(i=0;i<row1;i++)
    {
        for(j=0;j<column2;j++)
        {
            result[i][j] = calculation(matrix1,matrix2,i,j,column1);
        }
    }
    printf("\n^_^The result is as follows:\n");
    for(i=0;i<row1;i++)
    {
        printf("|");
        for(j=0;j<column2;j++)
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
