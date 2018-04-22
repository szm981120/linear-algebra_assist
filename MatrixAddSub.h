#include <stdio.h>
#include <stdlib.h>
#define AddSubM 10

//¾ØÕó¼Ó¼õ  MatrixAddSub
void MatrixAddSub()
{
    int matrix1[AddSubM][AddSubM],matrix2[AddSubM][AddSubM],result[AddSubM][AddSubM];
    int row,column;//ÐÐ ÁÐ
    int i,j;
    int choice;
    char ch,enter;
    printf("|-------------------------------------------|\n");
    printf("   This is a matrix add and subtraction calculator.\n\n");
    printf("^_^Please input the row and the column of the first matrix:");
    scanf("%d %d",&row,&column);
    printf("^_^Please input the elements of the first matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("\n^_^Please input the elements of the second matrix:\n  (Notice:the second matrix's size is %d*%d)\n",row,column);
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    printf("\nPlease input your choice :add or subtraction\n");
    printf("1--add\n");
    printf("2--subtraction\n");
    scanf("%d", &choice);
    if(choice==1)
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                result[i][j] = matrix1[i][j]+matrix2[i][j];
            }
        }
    }
    else if(choice==2)
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                result[i][j] = matrix1[i][j]-matrix2[i][j];
            }
        }
    }
    else
    {
        printf("The choice you entered is incorrect\n");
        exit(0);
    }
    printf("\n^_^The result is as follows:\n");
    for(i=0;i<row;i++)
    {
        printf("|");
        for(j=0;j<column;j++)
        {
            printf("%5d",result[i][j]);
        }
        printf("  |");
        printf("\n\n");
    }
    printf("\n\n|-------------------------------------------|\n");
    printf("Please press enter to exit.");
    while((ch=getchar())!='\n');
    scanf("%c",&enter);
    printf("%c",enter);
    return;
}

