#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define transN 10

void Rowtrans()
{
    int matrix[transN][transN],col[transN],simplify[transN];
    int row,column,i,j,k,p;
    int div,what,divsim;
    int startrow=0,startcol=0;
    int flag=1;
    char ch,enter;
    printf("|-------------------------------------------|\n");
    printf("   This is an elementary row transformation.\n\n");
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
    while(startrow<row-1 && startcol<column-1)
    {
        j=0;
        for(i=startrow;i<row;i++)
        {
            if(matrix[i][startcol]!=0)
            {
                col[j] = matrix[i][startcol];
                printf("%d\t",col[j]);
                j++;
            }
        }
        if(j>1)
    {
        div = Multiple(col, j); printf("%d\n",div);
        for(i=startrow;i<row;i++)
        {
            if(matrix[i][startcol]!=0)
            {
                what = div/matrix[i][startcol];
                for(j=startcol;j<column;j++)
                matrix[i][j] *= what;
            }
        }
        for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
        for(i=startrow+1;i<row;i++)
        {
            if(matrix[i][startcol]!=0)
            {
                for(j=0;j<column;j++)
                {
                    matrix[i][j] = matrix[i][j] - matrix[startrow][j];
                }
            }
            else continue;
        }
        for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
        startrow++;
        startcol++;
    }
        if(j<=1)
        startcol++;
        printf("---%d,%d\n",startrow,startcol);
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
    for(flag=1,i=0;i<row-1;i++)
    {
        flag = 1;
        printf("1flag=%d\t",flag);
        for(flag=1,j=i+1;j<row;j++)
        {
            flag = 1;
            printf("2flag=%d\t",flag);
            for(p=0;p<column;p++)
            {
                printf("3flag=%d\t",flag);
                if(matrix[i][p]!=matrix[j][p])
                {
                    flag=0;break;
                }
            }
            printf("4flag=%d\t",flag);
            if(flag==1)
            {
                for(p=0;p<column;p++)
                {
                    matrix[i][p]=0;
                }
            }
            printf("5flag=%d\t",flag);
        }
        printf("\n");
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
