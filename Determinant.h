/*本代码中排列组合的算法引用自http://blog.csdn.net/qq_33901297/article/details/52134672
    感谢博主分享！*/

/*  注意！！！：计算行列式前请先将define中的M和N的值给足够大的定义，以防止数据溢出！！！*/
/*  1！=1
    2！=2
    3！=6
    4！=24
    5！=120
    6！=720
    7！=5040
    8！=40320    */
#include <stdio.h>
#define DeterN 300//N为M的阶乘
#define DeterM 10//M为行列式的最大阶
int *result;//列order序号的组合数组
int *re_sult;//每个列组合的逆序数数组
int flag=0;
int z=0;
/************************************************************************/
/* 功能：实现两个整形参数值交换
/* 参数：
/*       lhs--int类型的指针，指向待交换数1的地址
/*       rhs--int类型的指针，指向待交换数2的地址
/************************************************************************/
void Swap(int *lhs, int *rhs)
{
    int t = *lhs;
    *lhs = *rhs;
    *rhs = t;
}
/************************************************************************/
/* 功能：实现全排列功能
/* 参数：
/*       source--整数数组，存放需要全排列的元素
/*       begin --查找一个排列的开始位置
/*       end   --查找一个排列的结束位置，当begin=end时，表明完成一个排列
/************************************************************************/
void FullPermutation(int source[], int begin, int end, int p)//得到逆序数组的数组result
{
    int i;
    if(flag==0)
    result = (int*) calloc(p*end , sizeof(int));
    flag=1;
    if (begin >= end) // 找到一个排列
    {
        for (i = 0; i < end; i++)
        {
            result[z*end+i] = source[i];
        }
        z++;//全局变量
    }
    else// 没有找完一个排列，则继续往下找下一个元素
    {
        for (i = begin; i < end; i++)
        {
            if (begin != i)
            {
                Swap(&source[begin], &source[i]); //交换
            }
            FullPermutation(source, begin + 1, end , p);// 递归排列剩余的从begin+1到end的元素
            if (begin != i)
            {
                Swap(&source[begin], &source[i]); // 回溯时还原
            }
        }
    }
}
int coefficient(int *result,int *re_sult,int p,int order)////得到逆序数的数组re_sult
{
    int i,j,k,count;
    for(i=0;i<p;i++)
    {
        count = 0;
        for(j=order-1;j>=0;j--)
        {
            for(k=0;k<j;k++)
            {
                if(result[i*order+k]>result[i*order+j])
                {
                    count++;
                }
            }
        }
        re_sult[i] = count;
    }
}
int Deter_minant(int (*determinant)[DeterM], int order)
{
    int input[DeterN],k;
    int i,p=1,j,det=0,an;
    char enter,ch;
    for (i = 0; i < order; i++)//初始化行序号数组：1,2,3,...
    {
        input[i] = i + 1;
    }
    for(i=1;i<=order;i++)
    {
        p = p*i;
    }
    re_sult = (int*) malloc(p*sizeof(int));
    FullPermutation(input, 0, order,p);//得到逆序数组的数组result
    coefficient(result,re_sult,p,order);//得到逆序数的数组re_sult
    for(i=0;i<p;i++)
    {
        an = 1;
        for(j=0;j<order;j++)
        {
            k = result[i*order+j];
            an = an*determinant[j][k-1];
        }
        if(re_sult[i]%2==0)
        {
            det = det+an;
        }
        else if(re_sult[i]%2==1)

        {
            det = det-an;
        }
    }
    free(result);
    free(re_sult);
    flag=0;
    z=0;
    return det;
}
