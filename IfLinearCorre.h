#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define transN 10

void IfLinearCorre()
{
    int matrix[transN][transN],col[transN],simplify[transN];
    int row,column,i,j,k,p;
    int div,what,divsim;
    int startrow=0,startcol=0;
    int flag=1;
    int num;
    printf("|-------------------------------------------|\n");
    printf("   This is a function to see if the vectors of a matrix is correlation.\n\n");
    printf("^_^Please input the row and the column of the matrix:");
    scanf("%d%d",&row,&column);
    printf("^_^Please input the elements of the matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    num = Matri_cialRank(matrix, row ,column);
    if(row==column)
    {
        printf("This is a square matrix.\n");
        if(num==row)
        {
            printf("The square matrix is linear independent and reversible.\n");
        }
        else
        {
            printf("The square matrix is linear dependent and irreversible.\n");
        }
    }
    else
    {
        if(num==column)
            printf("The group of column vectors of a matrix are linear independent.\n");
        else
            printf("The group of column vectors of a matrix are linear dependent.\n");
    }
}
