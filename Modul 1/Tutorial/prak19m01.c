#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Soal 1
/* Asumsikan jumlah murid selalu benar >0,
   input bilangan bulat dan angka tetapi validasi (0-100)
   standar deviasi ada rumusnya
*/

/*
int main() {
    // Kamus
    int n;
    int i;
    int nilai[500];
    double total = 0;
    double rata;
    int mini = 100;
    int maxi = 0;
    double totall = 0;
    double strd;


    printf("Masukkan jumlah murid: ");
    scanf("%d", &n);
    printf("\n");

    for (i=0; i<n; i++) {
        printf("Masukkan nilai murid absen %d : ", i+1);
        scanf("%d", &nilai[i]);

        while (nilai[i] < 0 || nilai[i] > 100) {
            printf("Input nilai tidak valid, coba lagi\n");
            printf("Masukkan nilai murid absen %d : ", i+1);
            scanf("%d", &nilai[i]);
        }

        total += nilai[i];

    }

    rata = total/n;

    printf("\nRata-Rata Kelas: %.2f\n", rata);

    for (i=0; i<n; i++) {
        if (nilai[i] < mini) {
            mini = nilai[i];
        }

        if (nilai[i] > maxi) {
            maxi = nilai[i];
        }
    }

    printf("Nilai Terendah: %d\n", mini);
    printf("Nilai Tertinggi: %d\n", maxi);

    for (i=0; i<n; i++) {
        totall += (pow(nilai[i] - rata, 2));

    }

    strd = sqrt(totall/n);
    printf("Standard Deviasi: %.2f\n", strd);

    printf("Murid yang harus remedial adalah absen:\n");

    for (i=0; i<n; i++) {
        if (nilai[i] < 80) {
            printf("%d", i+1);
            printf("\n");
        }

    }

    return 0;
}
*/

// Soal 2
int main() {
    // Asumsikan a dan b maksimal 10, tidak perlu divalidasi
    // Asumsikan masukkan sesuai, angka yang bulat dari 0-9, tidak perlu validasi
    // Kamus
    int na;
    int nb;
    int i;
    int j;
    int arra[10];
    int arrb[10];
    int sama = 0;

    printf("Masukkan banyaknya elemen A : ");
    scanf("%d", &na);

    for (i=0; i<na; i++) {
        printf("Masukkan elemen A ke-%d : ", i+1);
        scanf("%d", &arra[i]);

    }

    printf("Masukkan banyaknya elemen B : ");
    scanf("%d", &nb);

    for (i=0; i<nb; i++) {
        printf("Masukkan elemen A ke-%d : ", i+1);
        scanf("%d", &arrb[i]);

    }

    if (na!= nb) {
        printf("Jadi, B bukan anagram dari A");
    }

    else {

        for (i=0; i<na; i++) {
            for (j=0; j<nb; j++) {
                if (arra[i] == arrb[j]) {
                    sama += 1;
                    arrb[j] = -1;
                    break;

                }
                else {
                    sama += 0;
                }

            }
        }

        if (sama < na) {
            printf("Jadi, B bukan anagram dari A");
        }
        else {
            printf("Jadi, B adalah anagram dari A");
        }

    }

    return 0;
}
