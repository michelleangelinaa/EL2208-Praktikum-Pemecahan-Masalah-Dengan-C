#include <stdio.h>
#define MAX_ENTRY 20

int main () {
    // Deklarasi array of int
    int arr[MAX_ENTRY];
    int entry_amt;
    int i;

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
        for (i=0; i<entry_amt; i++) {
            // Elemen ditemukan
            if (arr[i] == key) {
                found = 1;
                idx = i;
                break;
            }

        }

        // Cetak hasil pencarian
        if (found)
            printf("Bilangan %d ditemukan pada indeks %d.\n", key, idx);
        else
            printf("Bilangan %d tidak ada.", key);
    }

    return 0;
}

