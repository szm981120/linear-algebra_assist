#include <stdio.h>
#include <stdlib.h>
#include "Minofcol.h"
#include "Multiple.h"
#include "Division.h"
#include "MatrixMul.h"
#include "Rowtrans.h"
#include "MatrixAddSub.h"
#include "MatrixRank.h"
#include "IfLinearCorre.h"
#include "CramerRule.h"
#include "Determinant2.h"

void MatrixMul();
void Rowtrans();
void MatrixAddSub();
int Matri_cialRank();
void IfLinearCorre();
void CramerRule();
int Minofcol();
int Multiple();
int Division();
int Deter_minant(int (*determinant)[DeterM], int order);

int main()
{
    int choose;
    int order;
    int rank;
    int determinant[DeterN][DeterM], det;
    int i,j;
    printf("|*************Linear Assist*****************|\n");
    printf("|***************Main Menu*******************|\n");
    printf("|                                           |\n");
    printf("|   1.Matrix multiplication calculator.     |\n");
    printf("|   2.Elementary row transformation.        |\n");
    printf("|   3.Determinant calculator.               |\n");
    printf("|   4.Matrix add and subtraction calculator.|\n");
    printf("|   5.Seek the rank of the appointed matrix.|\n");
    printf("|   6.See if the vectors of a matrix is correlation.|\n");
    printf("|   7.Cramer's rule using.                  |\n");
    printf("|                                           |\n");
    printf("|***************Long line*******************|\n\n");
    printf("Please input your choose :");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:MatrixMul();break;//一般矩阵乘法
        case 2:Rowtrans();break;//一般矩阵（各元素必须为整数）行初等变换
        case 3:
        printf("|-------------------------------------------|\n");
        printf("   This is a determinant calculator.\n\n");
        printf("^_^Please input the order of determinant:");
        scanf("%d", &order);
        printf("^_^Please input the elements of determinant:\n");
        for(i=0;i<order;i++)
        {
            for(j=0;j<order;j++)
            {
                scanf("%d",&determinant[i][j]);
            }
        }
        det = Deter_minant(determinant, order);
        printf("The result of the det is %d ^_^\n\n",det);
        printf("\n|-------------------------------------------|\n");
        break;//方阵行列式
        case 4:MatrixAddSub();break;//一般矩阵加减法
        case 5:rank = Matri_cialRank();break;//计算输入矩阵的秩
        case 6:IfLinearCorre();break;
        case 7:CramerRule();break;
        default:break;
    }
    return 0;
}
