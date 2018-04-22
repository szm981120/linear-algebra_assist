#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define transN 10

void Rowtrans(int matrix[transN][transN], int pRow[], int row, int column)
{
    int col[transN],simplify[transN];
    int i,j,k,p;
    int div,what,divsim;
    int startrow=0,startcol=0;
    int flag=1, maxflag;
    int *temprow;
    char ch,enter;
    while(startrow<row-1 && startcol<column-1)//进行操作的条件
    {
        j=0;
        for(i=startrow;i<row;i++)
        {
            if(matrix[i][startcol]!=0)
            {
                col[j] = matrix[i][startcol];
                j++;
            }
        }
        if(j>1)
        {
            div = Multiple(col, j);//求公倍数
            for(i=startrow;i<row;i++)
            {
                if(matrix[i][startcol]!=0)
                {
                    what = div/matrix[i][startcol];
                    for(j=startcol;j<column;j++)
                    matrix[i][j] *= what;//乘倍
                }
            }
            for(i=startrow;i<row-1;i++)
            {
                maxflag = i;
                for(j=i+1;j<row;j++)
                {
                    if(matrix[j][startcol] > matrix[maxflag][startcol])
                    {
                        maxflag = j;
                    }
                }
                memcpy(pRow, matrix[maxflag], column*sizeof(int));
                memcpy(matrix[maxflag], matrix[i], column*sizeof(int));
                memcpy(matrix[i], pRow, column*sizeof(int));
            }
            for(i=startrow+1;i<row;i++)
            {
                if(matrix[i][startcol]!=0)
                {
                    for(j=0;j<column;j++)
                    {
                        matrix[i][j] = matrix[i][j] - matrix[startrow][j];//行变换
                    }
                }
                else continue;
            }
            startrow++;
            startcol++;
        }
        if(j<=1)
        startcol++;
    }
    for(i=0;i<row;i++)
    {
        k = 0;
        for(j=0;j<column;j++)
        {
            if(matrix[i][j]!=0)
            {
                simplify[k] = matrix[i][j];
                k++;
            }
        }
        if(k>1)
            divsim = Division(simplify , k);
        else if(k==1)
        {
            divsim = simplify[0];
        }
        else continue;
        for(j=0;j<column;j++)
        {
            if(matrix[i][j]!=0)
            {
                matrix[i][j] = matrix[i][j] / divsim;
            }
        }
    }
    printf("\n^_^The matrix after the elementary row transformation is as follows:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
    printf("Please press enter to exit.");
    while((ch=getchar())!='\n');
    scanf("%c",&enter);
    printf("%c",enter);
    return;
}
