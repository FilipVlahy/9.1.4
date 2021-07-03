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

char mat_create_random_unimodular(MAT *mat)
{
    int determinant=0;

    //mat_unit(mat);
    mat_random(mat);

    if(mat->rows!=mat->cols)
        determinant = 1;
    else
    {

    }

    return determinant;
}

int main(void)
{
    MAT *mat;
    char determinant;

    mat=mat_create_with_type(3,3);
    mat_print(mat);
    determinant=mat_create_random_unimodular;

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