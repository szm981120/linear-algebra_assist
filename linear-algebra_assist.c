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
#include "IfPosiNega.h"
#include "PropeofSolu.h"
#include "InverseMatrix.h"


void MatrixMul();
void Rowtrans(int (*matrix)[transN], int pRow[], int row, int column);
void MatrixAddSub();
void IfLinearCorre();
void CramerRule();
void IfPosiNega();
void PropeofSolu();
int Minofcol();
int Multiple();
int Division();
int Deter_minant(int (*determinant)[DeterM], int order);
int Matri_cialRank(int (*matrix)[transN], int row ,int column);
int InverseMatrix(int (*matrixIn)[InverseN], int order);
int main()
{
    int choose;
    int order, orderinverse;
    int rank;
    int determinant[DeterN][DeterM], det;
    int matrix_rowtrans[transN][transN], matrix_rank[transN][transN], matrix_inverse[InverseN][InverseN];
    int rowrank, columnrank;
    int rowtran, columntran, pRow[transN];
    int i,j;
    printf("\t\t|*******\\\\********//***********Linear Assist************\\\\********//*******|\n");
    printf("\t\t|*********\\\\****//**************Main Menu******************\\\\****//********|\n");
    printf("\t\t|                                                                          |\n");
    printf("\t\t|   1.Matrix multiplication calculator.                                    |\n");//矩阵乘法
    printf("\t\t|   2.Elementary row transformation.                                       |\n");//行初等变换
    printf("\t\t|   3.Determinant calculator.                                              |\n");//行列式
    printf("\t\t|   4.Matrix add and subtraction calculator.                               |\n");//矩阵加减
    printf("\t\t|   5.Seek the rank of the appointed matrix.                               |\n");//求秩
    printf("\t\t|   6.See if the vectors of a matrix is correlation.                       |\n");//列向量是否线性相关
    printf("\t\t|   7.Cramer's rule using.                                                 |\n");//克莱默法则
    printf("\t\t|   8.Judge the quadratic form whether it is positive or negative definite.|\n");//判断矩阵是否为二次型对应矩阵，该二次型是否正定、负定
    printf("\t\t|   9.Consider the properties of solutions of linear equations             |\n");//考虑线性方程组解的情况
    printf("\t\t|   10.Seek the inverse matrix of the appointed matrix.                    |\n");//求可逆阵
    printf("\t\t|                                                                          |\n");
    printf("\t\t|********(￣▽￣)\"**************Long line*****************(￣▽￣)\"********|\n\n");
    printf("Please input your choose :");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:MatrixMul();break;//一般矩阵乘法
        case 2://一般矩阵（各元素必须为整数）行初等变换
            printf("|-------------------------------------------|\n");
            printf("   This is an elementary row transformation.\n\n");
            printf("^_^Please input the row and the column of the matrix:");
            scanf("%d%d",&rowtran,&columntran);//输入要变换矩阵的行和列
            printf("^_^Please input the elements of the matrix:\n");
            for(i=0;i<rowtran;i++)//输入要变换矩阵的元素
            {
                pRow[i] = matrix_rowtrans[i];
                for(j=0;j<columntran;j++)
                {
                    scanf("%d",&matrix_rowtrans[i][j]);
                }
            }
            Rowtrans(matrix_rowtrans, pRow, rowtran, columntran);
            break;
        case 3://方阵行列式
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
            break;
        case 4:MatrixAddSub();break;//一般矩阵加减法
        case 5://计算输入矩阵的秩
            printf("|-------------------------------------------|\n");
            printf("   This is a calculator to seek the rank of a matrix .\n\n");
            printf("^_^Please input the row and the column of the matrix:");
            scanf("%d%d",&rowrank,&columnrank);
            printf("^_^Please input the elements of the matrix:\n");
            for(i=0;i<rowrank;i++)
            {
                for(j=0;j<columnrank;j++)
                {
                    scanf("%d",&matrix_rank[i][j]);
                }
            }
            rank = Matri_cialRank(matrix_rank, rowrank, columnrank);
            printf("The matricial rank is %d", rank);
            break;
        case 6:IfLinearCorre();break;//方阵可逆性; 列向量的线性相关性;
        case 7:CramerRule();break;//Cramer 法则;
        case 8:IfPosiNega();break;//矩阵是否正定;
        case 9:PropeofSolu();break;//线性方程组的解情况的判定
        case 10:
            printf("|-------------------------------------------|\n");
            printf("   To seek the inverse matrix of the appointed matrix .\n\n");
            printf("^_^Please input the order of the matrix:");
            scanf("%d",&orderinverse);
            printf("^_^Please input the elements of the matrix:\n");
            for(i=0;i<orderinverse;i++){
                for(j=0;j<orderinverse;j++){
                    scanf("%d",&matrix_inverse[i][j]);
                }
            }
            InverseMatrix(matrix_inverse, orderinverse);break;//求逆矩阵
        default:break;
    }
    return 0;
}
