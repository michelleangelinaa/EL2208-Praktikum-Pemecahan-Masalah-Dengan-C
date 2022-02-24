/*
Objective: Membuat sebuah program yang dapat menerima masukan berupa nama barang tersebut kemudian
menampilkan informasi jumlah dan harga dari barang tersebut. Masukan yang diberikan dijamin sudah
benar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Kamus
    FILE *fp; // Filenya
    int i;
    char barang[4][10]; // Array of string dengan isi 4 elemen, masing-masing elemen berisi maksimal 10 karakter
    int jumlah[4]; // Array of integer dengan isi 4 elemen
    int harga[4]; // Array of integer dengan isi 4 elemen
    char pilih[10]; // Untuk pilihan dari user

    // Buat ngebuka filenya, "r" berarti read
    fp = fopen("barang.txt", "r"); 

    // Bentuk format dalam txtnya: <Nama Barang>, <Jumlah Barang>, <Harga Barang>
    
    // Asumsikan program ini hanya untuk file barang.txt dengan isi yang telah ditentukan, jadi tidak bisa diganti-ganti
    for (i=0; i<4; i++) {
        fscanf(fp, "\n%[^,],", barang[i]); // %[^,], untuk menghilangkan pemisah koma, nanti stringnya bakal dimasukin ke array barang
        fscanf(fp, "%d,", &jumlah[i]); // ada tanda "," setelah %d buat nyamain format pemisah, yang keambil cuma angkanya
        fscanf(fp, "%d", &harga[i]); // masuk ke array harga
    }

    // Masukan dari user
    printf("Masukkan nama barang: ");
    scanf("%s", pilih);

    //Pencarian barang
    for (i=0; i<4; i++) {
        if (strcmp(barang[i], pilih) == 0) { // strcmp itu fungsi dari string.h, untuk komparasi 2 string, beda sama python
            // Output
            printf("%s memiliki harga Rp. %d dengan jumlah barang %d.\n", barang[i], harga[i], jumlah[i]);
        }
    }

    // Jangan lupa ditutup lagi
    fclose(fp);
    
    return 0;
}