#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define fabN 10

int Multiple(int *col, int rowf)
{
    int k=1,flag=1,i,j;
    int mul=1,fabcol[fabN];
    for(i=0;i<rowf;i++)
    {
        fabcol[i] = (int)fabs(col[i]);
    }
    k = Minofcol(fabcol, rowf);
    while(1)
    {
        for(flag=1,i=0;i<rowf;i++)
        {
            if(fabcol[i]%k!=0)
            {
                flag = 0;
            }
        }
        if(flag==1)
        {
            for(j=0;j<rowf;j++)
            {
                mul = mul*fabcol[j];
            }
            return mul/k;
        }
        k--;
    }
}
