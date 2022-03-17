/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 4 - Structures and Dynamic Arrays
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 12 Maret 2021
 *  Nama File           : tutorial-04-arr.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Source code tutorial untuk modul 04, materi array dinamis.
 */

/** Perintah Kompilasi
 * 
 * Linux/MacOS  - gcc -o tutorial-04-arr tutorial-04-arr.c
 * Windows      - gcc -o tutorial-04-arr.exe tutorial-04-arr.c
 * 
 * atau dengan Makefile:
 * 
 * Linux/MacOS - make arr
 */

#include <stdio.h>
// stdlib dibutuhkan untuk manipulasi memori (i.e. malloc, calloc, etc)
#include <stdlib.h>

// Jumlahkan isi array dinamis arr dengan ukuran arr_size.
int sum_arr(int* arr, int arr_size) {
    int sum = 0;

    for (int i = 0; i < arr_size; ++i)
        sum += arr[i];
    
    return sum;
}

int main() {
    // Deklarasi array dinamis
    // Pointer to int yang akan menyimpan address elemen pertama array
    int* arr = NULL;
    // Ukuran array dinamis sejauh ini
    int arr_size = 0;
    // Variabel penyimpan input sementara sebelum disimpan dalam array
    int temp;

    // Input array secara dinamis hingga input -1
    printf("Input elemen array (-1 untuk selesai): ");
    scanf("%d", &temp);

    // Loop selama input tidak sama dengan -1
    while (temp != -1) {
        // Catat penambahan ukuran array
        ++arr_size;

        // Alokasi memori tambahan untuk menampung input
        if (arr_size == 1)
            // Bila array belum diinisialisasi 
            // Reservasi memori sebesar 1 buah integer dengan malloc
            // malloc me-return pointer ke alamat memori yang telah direservasi 
            arr = (int*) malloc(sizeof(int));
        else
            // Bila array sudah diinisialisasi
            // Alokasi ulang dengan ukuran sebesar arr_size buah integer dengan realloc
            // realloc me-return pointer ke alamat memori yang telah direservasi
            arr = (int*) realloc(arr, arr_size * sizeof(int));

        // Assign nilai elemen terakhir array dengan input
        arr[arr_size - 1] = temp;

        // Alternatif: bagaimana kalau assignment diganti (*arr + arr_size - 1) = temp; ?

        // Input elemen berikutnya
        printf("Input elemen array (-1 untuk selesai): ");
        scanf("%d", &temp);
    }

    // Print seluruh isi array
    printf("\nIsi array:\n");
    for (int i = 0; i < arr_size; ++i)
        printf("%d\n", arr[i]);

    // Print jumlah isi array arr
    printf("Jumlah isi array: %d\n", sum_arr(arr, arr_size));

    // Reset isi array
    // Free memori yang digunakan
    free(arr);
    // Set ukuran array ke nol kembali
    arr_size = 0;

    // Input ukuran array
    printf("\nJumlah elemen array: ");
    scanf("%d", &arr_size);

    // Alokasi memori dan inisialisasi array sebesar arr_size buah integer
    arr = (int*) calloc(arr_size, sizeof(int));

    // Print seluruh isi array sebelum input
    printf("\nIsi array sebelum input:\n");
    for (int i = 0; i < arr_size; ++i)
        printf("%d\n", arr[i]);

    // Input isi array
    printf("\nInput isi array:\n");
    for (int i = 0; i < arr_size; ++i) {
        printf("Input elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print seluruh isi array
    printf("\nIsi array setelah input:\n");
    for (int i = 0; i < arr_size; ++i)
        printf("%d\n", arr[i]);

    // Free memori yang digunakan
    free(arr);

    return 0;
}