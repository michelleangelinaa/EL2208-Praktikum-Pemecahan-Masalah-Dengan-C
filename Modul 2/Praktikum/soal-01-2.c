/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : 01
*Hari dan Tanggal : Kamis, 24 Februari 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    : Gala Ramadhan Ilham Warno Putra (13218076)
*Nama File        : soal-01.c
*Deskripsi        : Membantu Pak Dody untuk membuat program yang membantu dia dalam menganalisis data bpm siswanya dengan beberapa pilihan menu.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define maxl 255                // MAXIMUM LENGTH

int main(){
    // KAMUS
    int i;                      // Variabel index untuk loop
    int j = 0;                  // Variabel untuk mengeluarkan urutan siswa di output "Siswa [j]"
    int pilih = 0;              // Memilih menu
    char nama[maxl][maxl];      // Array of nama siswa
    int bpm[maxl];              // Array of BPM siswa sesuai urutan

    char line[maxl];            // Penampungan sementara untuk membaca setiap baris text

    FILE *fp;
    char filenya[50];           // Penampungan nama file yang diinput
    char *token;                // Token pemisah data di setiap baris

    // KAMUS Kasus
    // Kasus 1
    int min = 500;            // Deklarasi awal untuk mencari BPM minimum, diasumsikan tidak ada data BPM mencapai 100000
    int idx = 0;               // Penyimpanan indeks

    // Kasus 2
    char searchname[maxl];
    char *nyari;
    int count = 0;

    // Kasus 3
    int bpmmax = 0;
    int bpmmin = 0;

    // INPUT
	printf("Masukkan nama file kelas : ");
    scanf("%s", filenya);

    fp = fopen(filenya, "r");

    // FILE NOT FOUND!!
      if (fp == NULL) {
        printf("Error : file invalid\n");
         return 0;
      }

    // File aman
    while(fgets(line, maxl, fp)) { // REFERENSI: Tutorial m-02
        // Membaca setiap baris, pemisahan data nama dan BPM menggunakan ,
        token = strtok(line, ",");
        strcpy(nama[i], token);

        token = strtok(NULL, "\n");
        bpm[i] = atoi(token);

        // Iterasi
        ++i;
    }

    fclose(fp);

    // Pemilihan menu
	printf("Pilihlah nomor menu dibawah ini : \n");
	printf("1. Cari siswa dengan bpm terkecil\n");
	printf("2. Cari siswa dengan nama nya\n");
	printf("3. Cari siswa dengan rentang bpm tertentu\n");
	printf("Masukkan nomor menu 1/2/3 : ");
	scanf("%d", &pilih);

	// Kasus
    if (pilih == 1) {
        /* Diasumsikan tidak ada siswa yang memiliki nilai bpm yang sama,
        sehingga nilai bpm minimum hanya terdapat pada satu siswa saja. */
        for (i=0; i<maxl; i++) {
            if (bpm[i] < min && bpm[i] > 0) { // Membandingkan setiap data mencari terkecil. Asumsikan BPM tidak pernah nol karena BPM tidak mungkin nol.
                min = bpm[i];                 // Overwrite
                idx = i;
            }
        }
        // Output
        printf("Siswa %c\n", '1');
        printf("Nama siswa : %s\n", nama[idx]);
        printf("Bpm siswa : %d\n", min);
    }

    else if (pilih == 2) {
        // Input tambahan
        printf("Masukkan nama siswa : ");
        scanf("%s", searchname);

        // REFERENSI: https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        j = 1;
        for (i=0; i<maxl; i++) {
            // REFERENSI: https://www.delftstack.com/howto/c/string-contains-in-c/
            nyari = strstr(nama[i], searchname); // Mengecek apakah ada substring searchname di nama-namanya
            if (nyari) { // Jika ada
                // Output
                printf("Siswa %d\n", j);
                printf("Nama siswa : %s\n", nama[i]);
                printf("Bpm siswa : %d\n", bpm[i]);
                count += 1; // Penampung banyaknya siswa untuk syarat yang "Hasil pencarian tidak ditemukan"
                j+=1;
            }
        }

        if (count == 0) { // Tidak ada siswa yang ditemukan
            printf("Hasil pencarian tidak ditemukan :(\n");
        }
    }

    else if (pilih == 3) {
    	printf("Masukkan batas atas bpm : ");
    	scanf("%d", &bpmmax);
        printf("Masukkan batas bawah bpm : ");
        scanf("%d", &bpmmin);

        j = 1;
        count = 0;
        for (i=0; i<maxl; i++) {
            if ((bpm[i] <= bpmmax) && (bpm[i] >= bpmmin)) { // BPM yang berada di batas itu termasuk diprint
                // Output
                printf("Siswa %d\n", j);
                printf("Nama siswa : %s\n", nama[i]);
                printf("Bpm siswa : %d\n", bpm[i]);
                j+=1;
                count+=1;
            }
        }

        if (count == 0) { // Tidak ada siswa yang ditemukan di interval tersebut
            printf("Hasil pencarian tidak ditemukan :(\n");
        }
    }

    else {
        printf("Error : Nomor menu invalid\n");
        return 0;
    }



	return 0;
}
