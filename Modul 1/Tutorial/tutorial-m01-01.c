/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
 *  Modul               : 1 - Overview of C Language
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 11 Februari 2022
 *  Nama File           : tutorial-m01-01.c
 *  Deskripsi           : Source code tutorial untuk modul 01.
 /

/** Perintah Kompilasi
 *
 * Linux/MacOS  - gcc -o tutorial-m01-01 tutorial-m01-01.c -lm
 * Windows      - gcc -o tutorial-m01-01.exe tutorial-m01-01.c
 *
 * atau dengan Makefile:
 *
 * Linux/MacOS  - make 01
 */

/* Catatan
 *
 * Sebuah kode tidak seharusnya memiliki komentar yang terlalu
 * banyak seperti kode ini. Kode ini sengaja dibuat dengan
 * komentar yang rinci untuk membantu pemahaman.
 */

// Preprocessor Directives
// Files inclusion
#include <stdio.h>
#include <math.h>

// Macro definition
// Bilangan Euler
#define EULER 2.71828

int main() {
    // Deklarasi variabel
    int i;
    float f;
    char c;

    /* Blok input nilai variabel
     *
     * Catatan:
     * Saat input, gunakan tanda ampersand (&) di depan nama variabel.
     * Hal ini ditujukan untuk merujuk alamat memori dari variabel,
     * alih-alih nilai variabel.
     */
    printf("-- Fase Masukan\n");
    printf("Masukkan nilai bilangan bulat i: ");
    scanf("%d", &i);
    // Input char
    /* Trik:
     *  Tambahkan spasi di depan placeholder untuk mengabaikan karakter
     *  newline dari input sebelumnya.
     */
    printf("Masukkan nilai karakter c: ");
    scanf(" %c", &c);
    printf("Masukkan nilai bilangan real f: ");
    scanf("%f", &f);

    /*Blok echo nilai variabel
     *
     * Print nilai variabel yang telah di-input.
     */
    printf("\n-- Fase Keluaran\n");
    printf("Nilai bilangan bulat i: %d\n", i);
    printf("Nilai karakter c: %c\n", c);
    // Print float dengan formatting 3 angka di belakang koma
    printf("Nilai bilangan real f: %.3f\n", f);

    /* Blok assignment dan ekspresi
     *
     */
    // Contoh ekspresi perkalian
    i = i * 2;
    printf("Nilai variabel i setelah dikali 2: %d\n", i);
    // Contoh assignment
    i = 5;
    printf("Nilai variabel i setelah assignment: %d\n", i);
    // Contoh perbandingan
    /* Karena C tidak memiliki variabel boolean, boolean dapat diwakili oleh int
     *  dengan false dinyatakan sebagai 0, dan true dengan bukan 0.
     *
     *  Bisa dicoba sendiri dengan kondisional:
     *      if (5) {...}, if (-2) {...}, atau if (0) {...}
     */
    printf("Apakah nilai i kurang dari 5: %d\n", i < 5);
    printf("Apakah nilai i sama dengan 5: %d\n", i == 5);

    /* Blok perhitungan
     *
     * Print nilai eksponen dengan beberapa metode.
     */
    printf("\n-- Contoh Perhitungan\n");
    printf("Nilai bilangan Euler: %.3f\n", EULER);
    // Print nilai eksponen i dengan fungsi eksponensial exp()
    printf("Dengan math.h - Hasil dari e^(%d): %.3f\n", i, exp(i));
    // Print nilai eksponen i dengan fungsi pangkat pow()
    printf("Dengan macro - Hasil dari e^(%d): %.3f\n", i, pow(EULER, i));

    // Return 0 mengindikasikan tidak ada error yang terjadi
    return 0;
}
