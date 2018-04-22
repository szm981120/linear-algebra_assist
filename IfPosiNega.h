#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 10

void IfPosiNega()
{
    int matrix[M][M], mat1[M][M], result[M];
    int n;
    int i,j,k;
    int flagIf = 1;
    char ch,enter;
    printf("|-------------------------------------------|\n");
    printf("   Judge the quadratic form whether it is positive or negative definite\n\n");
    printf("^_^Please input the order of the quadratic form:");
    scanf("%d", &n);//输入二次型的矩阵的阶数
    printf("^_^Please input the elements of the quadratic form:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);//输入二次型矩阵的元素
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(matrix[i][j]!=matrix[j][i])
            {
                flagIf = 0;
                break;
            }
        }
        if(flagIf==0)break;
    }//判断是否为二次型
    if(flagIf==0)
    {
        printf("What you have entered is not a quadratic form\n");
        system("pause");
        exit(0);
    }
    else
    {
        for(k=1;k<=n;k++)
        {
            for(i=0;i<k;i++)
            {
                for(j=0;j<k;j++)
                {
                    mat1[i][j] = matrix[i][j];
                }
            }
            result[k-1] = Deter_minant(mat1, k);
        }
        for(k=0;k<n;k++)
        {
            if(result[k]<=0)
            {
                flagIf = 0;
                break;
            }
        }
        if(flagIf==1)
        {
            printf("The quadratic form is positive definite\n");
        }
        else
        {
        flagIf = 1;
        for(k=0;k<n;k=k+2)
        {
            if(result[k]>=0||result[k+1]<=0)
            {
                flagIf = 0;
                break;
            }
        }
        if(flagIf==1) printf("The quadratic form is negative definite\n");
        else printf("The quadratic form is neither negative nor positive definite\n");
        }
    }
    printf("\n\n|-------------------------------------------|\n");
    printf("Please press enter to exit.");
    while((ch=getchar())!='\n');
    scanf("%c",&enter);
    printf("%c",enter);
    return 0;
}
