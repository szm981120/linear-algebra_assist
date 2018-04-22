#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define transN 10
//主函数里加上case 5:ret = MatricialRank(); printf("The matricial rank is %d", ret);
int Matri_cialRank()
{
    int matrix[transN][transN],col[transN],simplify[transN];
    int row,column,i,j,k,p;
    int div,what,divsim;
    int startrow=0,startcol=0;
    int flag=1;
    int num = 0;
    printf("|-------------------------------------------|\n");
    printf("   This is a calculator to seek the rank of a matrix .\n\n");
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
                j++;
            }
        }
        if(j>1)
    {
        div = Multiple(col, j);
        for(i=startrow;i<row;i++)
        {
            if(matrix[i][startcol]!=0)
            {
                what = div/matrix[i][startcol];
                for(j=startcol;j<column;j++)
                matrix[i][j] *= what;
            }
        }
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
    for(i=0;i<row-1;i++)
    {
        flag = 1;
        for(j=i+1;j<row;j++)
        {
            flag = 1;
            for(p=0;p<column;p++)
            {
                if(matrix[i][p]!=matrix[j][p])
                {
                    flag=0;break;
                }
            }
            if(flag==1)
            {
                for(p=0;p<column;p++)
                {
                    matrix[i][p]=0;
                }
            }
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(matrix[i][j]!=0)
            {
                num++;
                break;
            }
        }
    }
    printf("The matricial rank is %d", num);
    return num;
}
