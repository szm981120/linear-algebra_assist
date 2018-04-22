#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define InverseN 10
int InverseMatrix(int (*matrixIn)[InverseN], int order)
{
    int exmatrix[InverseN][InverseN*2];
    int pRow[InverseN];
    int exorder;

    int col[transN],simplify[transN];
    int i,j,k,p;
    int div,what,divsim;
    int start=0;
    int flag=1, maxflag;
    int *temprow;
    char ch,enter;

    for(i=0;i<order;i++){
        for(j=0;j<order;j++){
            exmatrix[i][j] = matrixIn[i][j];
        }
        for(j=order;j<order*2;j++){
            exmatrix[i][j] = 0;
        }
        exmatrix[i][i+order] = 1;
        pRow[i] = exmatrix[i];
    }
    exorder = order*2;
     while(start<order-1)//进行操作的条件
    {
        j=0;
        for(i=start;i<order;i++)
        {
            if(exmatrix[i][start]!=0)
            {
                col[j] = exmatrix[i][start];
                j++;
            }
        }
        if(j>1)
        {
            div = Multiple(col, j);//求公倍数
            for(i=start;i<order;i++)
            {
                if(exmatrix[i][start]!=0)
                {
                    what = div/exmatrix[i][start];
                    for(j=0;j<exorder;j++)
                    exmatrix[i][j] *= what;//乘倍
                }
            }
            for(i=start;i<order-1;i++)
            {
                maxflag = i;
                for(j=i+1;j<order;j++)
                {
                    if(exmatrix[j][start] > exmatrix[maxflag][start])
                    {
                        maxflag = j;
                    }
                }
                memcpy(pRow, exmatrix[maxflag], exorder*sizeof(int));
                memcpy(exmatrix[maxflag], exmatrix[i], exorder*sizeof(int));
                memcpy(exmatrix[i], pRow, exorder*sizeof(int));
            }
            for(i=start+1;i<order;i++)
            {
                if(exmatrix[i][start]!=0)
                {
                    for(j=0;j<exorder;j++)
                    {
                        exmatrix[i][j] = exmatrix[i][j] - exmatrix[start][j];//行变换
                    }
                }
                else continue;
            }
        }
        start++;
    }
    for(i=0;i<order;i++)
    {
        k = 0;
        for(j=0;j<exorder;j++)
        {
            if(exmatrix[i][j]!=0)
            {
                simplify[k] = exmatrix[i][j];
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
        for(j=0;j<exorder;j++)
        {
            if(exmatrix[i][j]!=0)
            {
                exmatrix[i][j] = exmatrix[i][j] / divsim;
            }
        }
    }
    start = 0;
    printf("\n^_^The inverse matrix is as follows:\n");
    for(i=0;i<order;i++)
    {
        for(j=0;j<exorder;j++)
        {
            printf("%8d",exmatrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
    while(start<order-1)//进行操作的条件
    {
        j=0;
        for(i=order-start-1;i>=0;i--)
        {
            if(exmatrix[i][exorder/2-start-1]!=0)
            {
                col[j] = exmatrix[i][exorder/2-start-1];
                j++;
            }
        }
        if(j>1)
        {
            div = Multiple(col, j);//求公倍数
            for(i=order-start-1;i>=0;i--)
            {
                if(exmatrix[i][exorder/2-start-1]!=0)
                {
                    what = div/exmatrix[i][exorder/2-start-1];
                    for(j=0;j<exorder;j++)
                    exmatrix[i][j] *= what;//乘倍
                }
            }
            printf("\n^_^The inverse matrix is as follows:\n");
    for(i=0;i<order;i++)
    {
        for(j=0;j<exorder;j++)
        {
            printf("%8d",exmatrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
            for(i=order-start-2;i>=0;i--)
            {
                if(exmatrix[i][exorder/2-start-1]!=0)
                {
                    for(j=0;j<exorder;j++)
                    {
                        exmatrix[i][j] = exmatrix[i][j] - exmatrix[order-start-1][j];//行变换
                    }
                }
                else continue;
            }
            printf("\n^_^The inverse matrix is as follows:\n");
    for(i=0;i<order;i++)
    {
        for(j=0;j<exorder;j++)
        {
            printf("%8d",exmatrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
        }
        start++;
        for(i=0;i<order;i++)
    {
        k = 0;
        for(j=0;j<exorder;j++)
        {
            if(exmatrix[i][j]!=0)
            {
                simplify[k] = exmatrix[i][j];
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
        for(j=0;j<exorder;j++)
        {
            if(exmatrix[i][j]!=0)
            {
                exmatrix[i][j] = exmatrix[i][j] / divsim;
            }
        }
    }
    }
    for(i=0;i<order;i++)
    {
        k = 0;
        for(j=0;j<exorder;j++)
        {
            if(exmatrix[i][j]!=0)
            {
                simplify[k] = exmatrix[i][j];
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
        for(j=0;j<exorder;j++)
        {
            if(exmatrix[i][j]!=0)
            {
                exmatrix[i][j] = exmatrix[i][j] / divsim;
            }
        }
    }
    printf("\n^_^The inverse matrix is as follows:\n");
    for(i=0;i<order;i++)
    {
        for(j=0;j<exorder;j++)
        {
            printf("%5d",exmatrix[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
    return;
}
