// Objective: Menerima sebuah bilangan N sebagai jumlah mahasiswa kemudian menampilkan nilai mahasiswa yang bernilai di atas rata-rata.

// Preprocessor Directives
// Files inclusion
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Kamus
    int i;
    int n;
    int nilai[100];
    int total = 0;
    int rata;
    
    // Asumsikan user hanya menginput angka, tidak ada input character

    // Penerimaan bilangan N
    printf("Masukkan jumlah nilai mahasiswa (N): ");
    scanf("%d", &n);

    // Pengecekan input N dari user, N > 0
    // Asumsikan jumlah mahasiswa (N) tidak pernah lebih dari 100
    while (n<0) {
        printf("Nilai N tidak valid, ulangi.\n");
        printf("Masukkan jumlah nilai mahasiswa (N): ");
        scanf("%d", &n);
    }
    
    // Penerimaan input nilai mahasiswa
    for (i=0; i<n; i++) {
        printf("Masukkan nilai mahasiswa: ");
        scanf("%d", &nilai[i]);

       // Nilai berupa bilangan bulat dengan rentang 0-100
        while (nilai[i]<0 || nilai[i]>100) {
            printf("Nilai tidak valid, ulangi.\n");
            printf("Masukkan nilai mahasiswa: ");
            scanf("%d", &nilai[i]);
        }

        total += nilai[i];

    }

    // Perhitungan rata-rata kelas
    rata = total/n;

    printf("Nilai mahasiswa yang di atas rata-rata:\n");
    
    // Output berupa nilai yang di atas rata-rata
    for (i=0; i<n; i++) {
        if (nilai[i] > rata) {
            printf("%d\n", nilai[i]);
        }
    }

    // Selesai
    return 0;
}
