/* EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 2 - Strings and External Files
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 18 Februari 2022
 *  Nama File           : tutorial-02.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Source code tutorial untuk modul 02.
 */

/* Perintah Kompilasi
 *
 * Linux/MacOS  - gcc -o tutorial-02 tutorial-02.c
 * Windows      - gcc -o tutorial-02.exe tutorial-02.c
 *
 * atau dengan Makefile:
 *
 * Linux/MacOS  - make 01
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Panjang maksimum entry
#define MAX_LEN 255

int main () {

    // Input nama file
    char filename[MAX_LEN];
    printf("\nMasukkan nama file: ");
    scanf("%s", &filename);

    // Buka file untuk dibaca
    FILE* stream = fopen(filename, "r");

    // Array mama mahasiswa
    char names[MAX_LEN][MAX_LEN]; //MAX_LEN 255
    // Array nilai mahasiswa
    float score[MAX_LEN];

    // Variabel penyimpan baris dari file sementara
    char line[MAX_LEN];

    // Variabel penyimpan gender
    char gender[MAX_LEN][MAX_LEN];

    // Token penyimpan string sementara untuk parsing
    char* token;

    // Iterator penanda indeks array,
    // pada akhir iterasi nilai i akan sama dengan jumlah baris pada file // karena ada /0 nya
    int i = 0;

    // Baca file baris demi baris hingga habis
    while(fgets(line, MAX_LEN, stream)) { // ngambil, masukin ke line, pake maxnya 255, dari stream
        // Parse baris
        // Ambil string pada baris hingga tanda koma (koma tidak ikut dibaca)
        token = strtok(line, ",");

        // Copy string dari token ke array nama
        strcpy(names[i], token);

        token = strtok(NULL, ",");

        score[i] = atof(token);

        token = strtok(NULL, "\n");

        strcpy(gender[i], token);

        // Iterasi
        ++i;
    }

    // Cari nilai maksimum, minimum, dan rata-rata nilai
    float max = score[0];
    float min = score[0];
    float sum = score[0];

    // Index nilai maksimum dan minimum pada array
    int max_idx = 0;
    int min_idx = 0;

    for (int j = 1; j < i; j++) {
        // Cari nilai maksimum dan minimum
        printf("ini j = %d\n", j);
        if (score[j] > max) {
            max = score[j];
            max_idx = j;
        }
        if (score[j] < min) {
            min = score[j];
            min_idx = j;
        }

        // Jumlahkan nilai untuk menghitung rata-rata
        sum += score[j];
    }

    // Nilai rata-rata
    float mean = sum / i;

    // Print semua nama dan nilai
    for (int j = 0; j < i; ++j)
        printf("%s memperoleh nilai %.2f\n", names[j], score[j]);

    // Print statistik
    printf("\nStatistik:\n");
    printf("Nilai tertinggi: %.2f, atas nama %s, %s\n", max, names[max_idx], gender[max_idx]);
    printf("Nilai terendah: %.2f, atas nama %s, %s\n", min, names[min_idx], gender[min_idx]);
    printf("Nilai rata-rata: %.2f\n", mean);

    // Nama sebagai kunci pencarian
    char key[MAX_LEN];

    // Input kunci pencarian
    printf("\nCari nilai atas nama: ");
    scanf("%s", &key);

    // Hitung panjang nama dengan strlen dan tampilkan sebagai long int
    printf("%s terdiri atas %ld karakter.\n", key, strlen(key));

    // Cari nama hingga ditemukan atau hingga array habis
    int found = 0;
    int j = 0;

    while (j < i && !found) {
        // Perbandingan string, akan bernilai 0 bila kedua string sama persis
        // maka dari itu, false berarti cocok.
        // String tidak bisa dikomparasi dengan operator == atau !=, gunakan strcmp
        if (!strcmp(key, names[j])) { //strcmp kalo nemu ngehasilin 0 bukan 1
            found = 1;
        }
        else
            ++j;
    }

    // Print nilai kunci pencarian bila ditemukan
    if (found)
        printf("%s memperoleh nilai: %.2f\n", key, score[j]);
    else
        printf("%s tidak ada.\n", key);

    // Tutup file
    fclose(stream);

    return 0;
}
