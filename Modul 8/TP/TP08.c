#include <stdio.h>
#include <stdlib.h>
// Mengimplementasikan quick sort yang menggunakan prinsip divide and conquer, dimana program akan membagi dua array menjadi lebih besar dan lebih kecil dari suatu nilai patokan.

// Fungsi untuk menukar elemen
void swap(int *a, int *b) {
    // Variabel penampung sementara
    int temp = *a;

    // a diganti menjadi b
    *a = *b;
    // b diganti menjadi temp yang berisi a
    *b = temp;
}

// Fungsi pembagian secara parsial, bagian DIVIDE
int parsial(int data[], int last, int first) {
    // Mengambil elemen "pertama" queue, yaitu elemen terakhir dalam array
    int head = data[first];

    // Indeks untuk pergeseran
    int i = (last-1);

    int j;
    // Komparasi elemen, diawali dari indeks 0 sampai indeks 9
    for (j=last; j<first; j++) {
        // Jika lebih kecil dari patokan, akan ditukar, untuk dibagi menjadi dua bagian, yaitu grup lebih besar dan lebih kecil dari patokan
        if (data[j] <= head) {
        i++;

        // Ditukar
        swap(&data[i], &data[j]);
        }
    }

    // Tukar dengan elemen yang lebih besar, kemudian nilai patokan akan dipindah ke i+1
    swap(&data[i+1], &data[first]);

    // Mengembalikan indeksnya nilai patokan
    return (i+1);
}

// Bagian CONQUER
void sort(int data[], int last, int first) {
    if (last < first) {
        // Mengambil nilai pemisah parsialnya, patokannya
        int pemisah = parsial(data, last, first);

        // Rekursi sort untuk elemen yang lebih kecil dari patokan, di bagian kirinya, 1 indeks sebelumnya
        sort(data, last, pemisah-1); // pi-1 jadi indeks akhir
        // Rekursi sort untuk elemen yang lebih besar dari patokan, dibagian sebelah kanannya, 1 indeks setelahnya
        sort(data, pemisah+1, first); // pi+1 jadi indeks awal
    }
}

// MAIN
int main()
{
    int data[10] = {6,1,5,8,28,4,7,9,16,24};
    for(int i = 0;i<10;i++){
        printf("%d ",data[i]);
    }

    printf("\n");

    sort(data, 0, 9);
    printf("Sorted data: ");

    for(int i = 0;i<10;i++){
        printf("%d ",data[i]);
    }

    return 0;
}
