#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void kali(int row, int colomn, int **matriks);

int main(){
    int row, colomn;

    printf("Masukkan jumlah baris : ");
    scanf("%d", &row);

    printf("Masukkan jumlah kolom : ");
    scanf("%d", &colomn);

    int *matriks[row];
    for(int i = 0; i<row; i++){
        matriks[i] = (int * ) malloc (colomn * sizeof(int));
    }

    srand((unsigned) time(0));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colomn; j++)
        {
            matriks[i][j] = rand() % 10;
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }

    printf("Sekarang mau ngaliin\n");
    kali( row, colomn, matriks);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colomn; j++)
        {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void kali(int row, int colomn, int **matriks){
    int konstanta = 5;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < colomn; j++){
            matriks[i][j] *= konstanta;
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
    printf("Done\n\n");
}
