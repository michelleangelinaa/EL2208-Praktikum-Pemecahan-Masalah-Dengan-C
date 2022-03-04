#include <stdio.h>
#include <stdlib.h>

int kembalian(int* harga, int input, int barang, int net);

int main(){
    printf("Program perhitungan kembalian\n");

    int input, barang;
    printf("Masukkin jumlah uang : ");
    scanf("%d", &input);

    printf("Masukkin jumlah barang : ");
    scanf("%d", &barang);

    int harga[9] = {1000000, 500000, 100000, 50000, 20000, 10000, 5000, 2000, 1000};
    int net = input - barang;

    if (input > barang)
    {
        kembalian(harga, input, barang, net);
    }
    else if (input == barang)
    {
        printf("Tidak ada kembalian!");
    }
    else
    {
        printf("Uang anda tidak cukup!");
    }
    return 0;
}

int kembalian(int* harga, int input, int barang, int net){
    int freqLembar[9] = {0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 9; i++){
        int j = 0;
        while (net - harga[i] >= 0)
        {
            freqLembar[i] += 1;
            net -= harga[i];
            ++j;
        }
        if (freqLembar[i] != 0){
            printf("%d lembar uang %d\n", freqLembar[i], harga[i]);
        }
    }
    printf("%d coin", net);
}
