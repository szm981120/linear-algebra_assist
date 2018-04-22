#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Minofcol(int *fabcol, int rowf)
{
    int i,k,j;
    for(i=0;i<rowf-1;i++)
    {
        k = i;
        for(j=i+1;j<rowf;j++)
        {
            if(fabcol[j]<fabcol[k])
                k = j;
        }
    }
    return fabcol[k];
}
