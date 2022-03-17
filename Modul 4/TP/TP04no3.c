#include <stdio.h>
#include <stdlib.h>

typedef struct kelas{
int jumlah_mahasiswa;
int* daftar_nilai;
}PPMC;

int main(){
PPMC k01;

Praktikum Pemecahan Masalah dengan C (EL2208) | Tahun 2021-2022 | Semester Genap
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
}
