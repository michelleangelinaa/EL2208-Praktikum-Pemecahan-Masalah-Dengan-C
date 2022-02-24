/**EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : Overview of C Language
*Percobaan        : Soal 1 - Platform Rekomendasi Untuk Traveler
*Hari dan Tanggal : Kamis, 17 Februari 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    : Agape D'Sky (18319010)
*Nama File        : soal-01.c
*Deskripsi        : Membantu Mas Aris yang merekomendasi pilihan harga yang murah dan perjalanan yang singkat sehingga
                    Mas Aris tetap dapat menjadi seorang Part-Time Traveler serta segera pergi ke tempat impiannya, Cappadocia, Turki.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Kamus
    int n; // Untuk banyak data
    int i;
    int j;
    int pilih; // Untuk pilihan menu
    int arrprice[1000]; // Array of harga
    int arrtime[1000]; // Array of lama perjalanan jam
    int harga = 10000000; // Asumsikan harga tidak pernah melebihi 10 juta
    int lama = 100000; // Asumsikan lama perjalanan tidak pernah melebihi 100k jam


    printf("Masukan banyaknya data = "); // Masukin banyaknya data
    scanf("%d", &n);

    printf("Silahkan mulai pengisian data:\n");

    /* Asumsikan tidak mungkin kedua informasi,
       yaitu harga dan lama perjalanan,
       pada dua data yang berbeda memiliki nilai sama. */
    for (i=0; i<n; i++) {
        printf("Masukan data ke-%d (harga, lama perjalanan) = ", i+1);
        scanf("%d,", &arrprice[i]); // Array harga
        scanf("%d", &arrtime[i]); // Array lama perjalanan
    }


    // Milih menunya
    printf("\nPilihan menu\n");
    printf("1. Harga termurah\n");
    printf("2. Perjalanan tersingkat\n");
    printf("3. Tampilkan keduanya\n");

    printf("Pilih menu? (1/2/3) = ");
    scanf("%d", &pilih);

    // Cases
    // Karena template output tidak ada untuk kasus angka pilihan yang salah, asumsikan pengguna selalu menginput angka 1, 2, atau 3 saja.
    if (pilih == 1) {
        for (i=0; i<n; i++) {
            if (arrprice[i] < harga) { // waktu yang lebih singkat akan dioverwrite
                harga = arrprice[i];
                lama = arrtime[i];

            }
            else if (arrprice[i] == harga) { // Jika ketemu waktu yang sama
                for (j=i; j<n; j++) { // Membandingkan waktunya
                    if (arrtime[j] < lama) {

                        harga = arrprice[j];
                        lama = arrtime[j];
                    }
                }
            }
            else {
                lama = lama; // Kalo lebih besar ya tetep nilainya
                harga = harga;
            }
        }

        // Output
        printf("Berikut adalah detail pilihan harga termurah yang disarankan:\n");
        printf("Harga = Rp %d\n", harga);
        printf("Lama perjalanan = %d Jam\n", lama);

    }

    else if (pilih == 2) { // Waktu tersingkat
        for (i=0; i<n; i++) {
            if (arrtime[i] < lama) { // waktu yang lebih singkat akan dioverwrite
                lama = arrtime[i];
                harga = arrprice[i];
            }
            else if (arrtime[i] == lama) { // Jika ketemu waktu yang sama
                for (j=i; j<n; j++) {
                    if (arrprice[j] < harga) { // Membandingkan harganya
                        lama = arrtime[j]; 
                        harga = arrprice[j];
                    }
                }
            }
            else {
                lama = lama; // Kalo lebih besar ya tetep nilainya
                harga = harga;
            }
        }

        // Output
        printf("Berikut adalah detail pilihan perjalanan tersingkat yang disarankan:\n");
        printf("Harga = Rp %d\n", harga);
        printf("Lama perjalanan = %d Jam\n", lama);

    }


    else if (pilih == 3) {

         for (i=0; i<n; i++) {
            if (arrprice[i] < harga) { // waktu yang lebih singkat akan dioverwrite
                lama = arrtime[i];
                harga = arrprice[i];
            }
            else if (arrprice[i] == harga) { // Jika ketemu waktu yang sama
                for (j=i; j<n; j++) { // Membandingkan waktunya
                    if (arrtime[j] < lama) { 
                        lama = arrtime[j]; 
                        harga = arrprice[j];
                    }
                }
            }
            else {
                lama = lama; // Kalo lebih besar ya tetep nilainya
                harga = harga;
            }
        }



        // Output
        printf("Berikut adalah detail pilihan yang disarankan:\n");
        printf("Harga termurah:\n");
        printf("Harga = Rp %d\n", harga);
        printf("Lama perjalanan = %d Jam\n", lama);

        for (i=0; i<n; i++) {
            if (arrtime[i] < lama) { // waktu yang lebih singkat akan dioverwrite
                lama = arrtime[i];
                harga = arrprice[i];
            }
            else if (arrtime[i] == lama) { // Jika ketemu waktu yang sama
                for (j=i; j<n; j++) { // Membandingkan harganya
                    if (arrprice[j] < harga) {
                        lama = arrtime[j];
                        harga = arrprice[j];
                    }
                }
            }
            else {
                lama = lama; // Kalo lebih besar ya tetep nilainya
                harga = harga;
            }
        }

        // Output
        printf("Perjalanan tersingkat:\n");
        printf("Harga = Rp %d\n", harga);
        printf("Lama perjalanan = %d Jam\n", lama);

    }







    return 0;
}
