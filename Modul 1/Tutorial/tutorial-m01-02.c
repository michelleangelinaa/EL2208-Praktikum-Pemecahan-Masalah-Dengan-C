/* EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 1 - Overview of C Language
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Sabtu, 13 Februari 2021
 *  Nama File           : tutorial-01-02.c
 *  Deskripsi           : Source code tutorial untuk modul 01.
 */

/* Perintah Kompilasi
 *
 * Linux/MacOS  - gcc -o tutorial-m01-02 tutorial-m01-02.c
 * Windows      - gcc -o tutorial-m01-02.exe tutorial-m01-02.c
 *
 * atau dengan Makefile:
 *
 * Linux/MacOS  - make 02
 */

/* Catatan
 *
 * Sebuah kode tidak seharusnya memiliki komentar yang terlalu
 * banyak seperti kode ini. Kode ini sengaja dibuat dengan
 * komentar yang rinci untuk membantu pemahaman.
 */

#include <stdio.h>
#define MAX_ENTRY 20

int main () {
    // Deklarasi array of int
    int arr[MAX_ENTRY];
    int entry_amt;

    // Input jumlah masukan
    printf("Input jumlah masukan (maksimum 20): ");
    scanf("%d", &entry_amt);

    /* Struktur kontrol kondisional.
     *
     * Pada kasus ini digunakan untuk validasi input.
     */
    if (entry_amt <= 0 || entry_amt > 20)
        printf("Error, jumlah masukan salah.\n");
    else {
        /* Struktur kontrol iteratif.
         *
         * Pada kasus ini digunakan untuk input dan output elemen array.
         */

        // Input elemen array
        printf("\nMasukkan %d bilangan bulat:\n", entry_amt);

        for (int i = 0; i < entry_amt; ++i)
            scanf("%d", &arr[i]);

        // Print elemen array
        printf("\nIsi array: ");
        for (int i = 0; i < entry_amt; ++i)
            printf("%d ", arr[i]);

        /* Struktur kontrol kondisional.
         *
         * Pada kasus ini digunakan untuk mencari elemen dari array.
         * Digunakan karena pencarian tidak perlu dilanjutkan ketika
         * bilangan sudah ditemukan.
         */

        // Input bilangan nyang ingin dicari dalam array
        int key;

        printf("\n\nInput bilangan yang ingin dicari dalam array: ");
        scanf("%d", &key);

        // Cari bilangan dalam array
        int idx = 0;
        int found = 0;

        // Cari selama indeks masih di dalam batas array dan bilangan
        // belum ditemukan
        while (idx < entry_amt && !found) {
            // Elemen ditemukan
            if (arr[idx] == key)
                found = 1;
            else
                // Iterasi
                ++idx;
        }

        // Cetak hasil pencarian
        if (found)
            printf("Bilangan %d ditemukan pada indeks %d.\n", key, idx);
        else
            printf("Bilangan %d tidak ada.", key);
    }

    return 0;
}
