/* #include <stdio.h>
#include <stdlib.h>


typedef struct kelas{
    int jumlah_mahasiswa;
    int* daftar_nilai;
}PPMC;

int main(){
    PPMC k01;
    k01.jumlah_mahasiswa = 3;
    k01.daftar_nilai = (int*)malloc(k01.jumlah_mahasiswa * sizeof(int));
    k01.daftar_nilai[0] = 100;
    k01.daftar_nilai[1] = 65;
    k01.daftar_nilai[2] = 80;
    PPMC* k02;
    k02 = &k01;

    printf("%d\n",k01.daftar_nilai[0]);
    printf("%d\n",(&k01)->daftar_nilai[1]);
    printf("%d\n",(&k01)->daftar_nilai[2]);
    printf("%d\n",(*k02).daftar_nilai[0]);
    printf("%d\n",(k02)->daftar_nilai[1]);
    printf("%d\n",(*k02).daftar_nilai[2]);

    free(k01.daftar_nilai);

    return 0;
} */

// Objective: Implementasi fungsi addjenisbuku dan print. Fungsi addjenisbuku akan menambahkan jenis buku dan jumlahnya ke dalam array of buku sedangkan fungsi print berfungsi untuk mencetak isi array of buku.

#include <stdio.h>
#include <stdlib.h>


// Given struct dari TP
typedef struct book{
    int jenis_buku;
    int jumlah_buku;
} buku;

// addjenisbuku digunakan untuk nmenambah data ke dalam array struct
void addjenisbuku(int jenis, int jumlah, buku* perpustakaan, int *count) {
    buku b; // b adalah nama structurenya
    b.jenis_buku = jenis; // Inisiasi jenis buku ke array buku dummy
    b.jumlah_buku = jumlah; // Inisiasi jumlahnya ke array buku dummy
    perpustakaan[*count] = b; // Memasukkan array b, yaitu array buku dummy tadi ke array perpustakaannya
    *count+=1; // Penambahan indeks

}

// print untuk menampilkan data array buku ke layar
void print(int count, buku* perpustakaan) {
    for (int i=0; i<count; i++) {
        printf("jenis: %d, jumlah: %d\n", perpustakaan[i].jenis_buku, perpustakaan[i].jumlah_buku);
    } // perpustakaan = nama arraynya, [i] adalah data struct ke-1, print bagian data jenis_buku atau jumlah_buku
}

int main() {
    buku* perpus = (buku*) malloc(sizeof(buku)); // Menggunakan size data struct buku
    int banyak_jenis_buku = 0;

    // Penambahan data ke array struct perpus
    addjenisbuku(1, 5, perpus, &banyak_jenis_buku);
    addjenisbuku(2, 8, perpus, &banyak_jenis_buku);
    addjenisbuku(6, 20, perpus, &banyak_jenis_buku);

    print(banyak_jenis_buku, perpus);

    // Supaya tidak ada memory leak
    free(perpus);
    return 0;
}
