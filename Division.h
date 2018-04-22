#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DivN 10
int Division(int *simplify, int p)
{
    int k=1,flag=1,i;
    int fabsimplify[DivN];
    for(i=0;i<p;i++)
    {
        fabsimplify[i] = (int)fabs(simplify[i]);
    }
    k = Minofcol(fabsimplify, p);
    while(1)
    {
        for(flag=1,i=0;i<p;i++)
        {
            if(fabsimplify[i]%k!=0)
            {
                flag = 0;
            }
        }
        if(flag==1)
        {
            return k;
        }
        k--;
    }
}
