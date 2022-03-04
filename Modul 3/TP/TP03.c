// Objective: Membuat fungsi product yang bisa mengalikan isi matriks dengan 5 kemudian ditampilkan

#include <stdio.h>
#include <stdlib.h>

void product(int arr[0], int b, int c) { // 0 == initial point
    int cons = 5;

    for (int i=0; i<b; i++){ // Baris
        for(int j = 0; j<c; j++){ // Kolom
            arr[i *c + j] *= cons;
//            int m = i*c+j; == indeks array 1 dimensi, arr[0][3] (2 dimensi) = arr[3] (1 dimensi)
            }
    }
}

int main(){
    int b = 0; // Inisialisasi awal baris
    int c = 0; // Inisialisasi awal kolom

    printf("Jumlah baris: ");
    scanf("%d", &b);
    printf("Jumlah kolom: ");
    scanf("%d", &c);

    int arr[b][c]; // Inisiasikan matriks SETELAH tahu jumlah baris dan kolom

    // Input
    printf("Input matriks:\n");
    for(int i = 0; i < b; i++) {
            for(int j = 0; j < c; j++) {
                scanf("%d", &arr[i][j]);
            }
     }

    printf("\n");
    product(arr, b, c); // Pemanggilan fungsi product

    // Output
    printf("Hasil product:\n");
    for (int i=0;i<b;i++){
        for(int j = 0;j<c;j++){
            printf("%d\t",arr[i][j]);
            }
        printf("\n");
        }


    return 0;
}
