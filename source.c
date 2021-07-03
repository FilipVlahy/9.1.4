#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    unsigned int rows;
    unsigned int cols;
    float *elem;
}MAT;

MAT *mat_create_with_type(unsigned int rows, unsigned int cols)
{
    MAT *mat;

    mat=(MAT*)malloc(sizeof(MAT));

    mat->rows=rows;
    mat->cols=cols;
    mat->elem=(float*)malloc((rows*cols)*sizeof(float));

    return mat;
}

void mat_unit(MAT *mat)
{
    int i,j;

    for(i=0;i<mat->rows;i++)
    {
        for(j=0;i<mat->cols;j++)
        {
            if (i==j)
                mat->elem[mat->cols*i+j]=1;
            else
                mat->elem[mat->cols*i+j]=0;
        }
    }
}

void mat_random(MAT *mat)
{
    int i,n;

    n=mat->rows*mat->cols;

    for(i=0;i<n;i++)
        mat->elem[i]=rand()%3-1;
}

void mat_print(MAT *mat)
{
    int i,j;

    for(i=0;i<mat->rows;i++)
    {
        for(j=0;i<mat->cols;j++)
            printf("%.1f ",mat->elem[mat->cols*i+j]);
        puts("\n");
    }
}

MAT *tmp_mat(MAT *mat, unsigned int mat_i, unsigned int mat_j)
{
    int tmp_i,tmp_j;
    MAT *tmp_mat;

    tmp_mat = mat_create_with_type(mat->rows-1,mat->cols-1);    

    for(int i=0;i<mat->rows;i++)
    {
        for (int j=0;i<mat->cols;i++)
        {
            tmp_mat->elem[(mat->cols-1)*tmp_i+tmp_j]=mat->elem[mat->cols*i+j];
        }
              
    }

    return tmp_mat;
}

char mat_create_random_unimodular(MAT *mat)
{
    int determinant=0;

    //mat_unit(mat);
    //mat_random(mat);

    if(mat->rows!=mat->cols)
        determinant = 1;
    else if(mat->rows==1)
        determinant=mat->elem[0];
    else if(mat->rows==2)
        determinant=mat->elem[0]*mat->elem[3]-mat->elem[1]*mat->elem[2];
    else
    {
        for(int i=0;i<mat->rows;i++)
            determinant+=pow(-1,i)*mat->elem[i]*mat_create_random_unimodular(tmp_mat(mat,0,i));
    }

    return determinant;
}

int main(void)
{
    MAT *mat;
    char determinant;

    mat=mat_create_with_type(3,3);
    mat_random(mat);
    determinant=mat_create_random_unimodular(mat);
    mat_print(mat);

    if (determinant==1)
        puts("Unimodular.");
    else if (determinant==-1)
        puts("Unimodular.");
    else
        puts("Non-Unimodular.");

    free(mat->elem);
    free(mat);

    return 0;
}