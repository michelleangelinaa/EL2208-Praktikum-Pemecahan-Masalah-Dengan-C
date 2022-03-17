/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 4 - Structures and Dynamic Arrays
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 12 Maret 2021
 *  Nama File           : tutorial-04-struct.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Source code tutorial untuk modul 04, materi struct.
 */

/** Perintah Kompilasi
 * 
 * Linux/MacOS  - gcc -o tutorial-04-struct tutorial-04-struct.c
 * Windows      - gcc -o tutorial-04-struct.exe tutorial-04-struct.c
 * 
 * atau dengan Makefile:
 * 
 * Linux/MacOS - make struct
 */

#include <stdio.h>
#include <stdlib.h>

/** Struct Mahasiswa.
 * 
 * Berisi NIM dan IPK mahasiswa.
 */
typedef struct Mahasiswa {
    char nim[10];
    float ipk;
} Mahasiswa;

// Bandingkan IPK dua mahasiswa, return pointer ke mahasiswa dengan IPK lebih tinggi. 
// Bila IPK sama, return NULL pointer.
Mahasiswa* sarip(Mahasiswa* mhs_1, Mahasiswa* mhs_2) {
    // Solusi, inisialisasi dengan NULL
    Mahasiswa* bang_jago = NULL;

    // Bandingkan IPK
    if (mhs_1->ipk > mhs_2->ipk)
        bang_jago = mhs_1;
    else if (mhs_1->ipk < mhs_2->ipk)
        bang_jago = mhs_2;

    return bang_jago;
}

// Bucin akan menyita waktu dan membuat IPK turun :(, kurangi IPK mhs menjadi setengahnya.
void bucin(Mahasiswa* mhs) {
    mhs->ipk = mhs->ipk / 2;
}

int main() {
    // Deklarasi variabel dengan tipe Mahasiswa dan pointer to Mahasiswa
    Mahasiswa mhs, *mhs_pt;

    // Alokasi memori untuk pointer to Mahasiswa
    mhs_pt = (Mahasiswa*) malloc(sizeof(Mahasiswa));

    // Input data kedua mahasiswa
    // Perhatikan bahwa untuk mengakses member dari struct dapat digunakan operator dot (.), 
    // dan untuk mengakses member dari pointer to struct dapat digunakan operator arrow (->).
    printf("Input NIM Mahasiswa 1: ");
    scanf("%s", &(mhs.nim));
    printf("Input IPK Mahasiswa 1: ");
    scanf("%f", &(mhs.ipk));

    printf("Input NIM Mahasiswa 2: ");
    scanf("%s", &(mhs_pt->nim));
    printf("Input IPK Mahasiswa 2: ");
    scanf("%f", &(mhs_pt->ipk));

    // Print data mahasiswa yang telah diinput
    printf("\nMahasiswa 1 - NIM: %s, IPK: %.2f\n", mhs.nim, mhs.ipk);
    printf("Mahasiswa 2 - NIM: %s, IPK: %.2f\n", mhs_pt->nim, mhs_pt->ipk);

    // Cari mahasiswa dengan IPK lebih tinggi
    Mahasiswa* bang_jago = sarip(&mhs, mhs_pt);
    if (bang_jago != NULL)
        printf("\nBang jago - NIM: %s\n", bang_jago->nim);
    else
        printf("\nTiada bang jago di antara kita.\n");

    // Bucin itu tidak baik.
    bucin(&mhs);
    printf("\nSetelah bucin, IPK Mahasiswa 1 anjlok menjadi %.2f. Bersama, kita bisa hentikan ini.\n", mhs.ipk);
    
    return 0;
}