/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : Praktikum, No. 2
*Hari dan Tanggal : Kamis, 17 Maret 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    :	Hudzaifah Afif Al Fatih Nasution (13219031)
*Nama File        : soal-02.c
*Deskripsi        : Program untuk mengecek apakah matriks tersebut merupakan matriks hermitian atau bukan.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
	int real;
	int imag;
} complex;

// Untuk mempermudah, dibuat sebuah struct lagi yang membentuk suatu matrix kompleks berisi bilangan kompleks
typedef struct matrix {
    complex contents[100][100];
    int brs;
    int kol;
} matrix;

// Menginput matrix dari user
void inputmatrix(matrix *m, int brs, int kol) {
    m->brs = brs;
    m->kol = kol;
    int temp_real, temp_imag;

    complex temp_comp; // Dummy matrix
    for (int i=0; i<brs; i++) {
        for (int j=0; j<kol; j++) {
            // Input dari user sesuai template soal
            scanf("%d %d", &temp_real, &temp_imag);

            temp_comp.real = temp_real;
            temp_comp.imag = temp_imag;
            // Input ke dalam matrix m
            m->contents[i][j] = temp_comp;
        }
    }
}

matrix transpose(matrix m) {
    // Membuat matrix hasil transpose
    matrix transposed;
    // Pertukaran baris dan matrix
    transposed.brs = m.kol;
    transposed.kol = m.brs;

    for (int i=0; i<m.kol; i++) {
        for (int j=0; j<m.brs; j++) {
            // Transpose isi matrix
            transposed.contents[i][j] = m.contents[j][i];
        }
    }

    return transposed;
}

matrix conjugate(matrix m) {
    // Mengonjugasi bagian imajiner isi matrix
    for (int i=0; i< m.kol; i++) {
        for (int j=0; j< m.brs; j++) {
            // Conjugate bagian imajiner isi matrix
            if (m.contents[i][j].imag != 0) {
                m.contents[i][j].imag *= -1;
            }
        }
    }

    return m;
}

int isComplexSame(complex c1, complex c2) {
    // Membandingkan bilangan kompleksnya apakah sama
    return (c1.real == c2.real) && (c1.imag == c2.imag);
}

int isComplexNegated(complex c1, complex c2) {
    // Membandingkan bilangan kompleksnya apakah ternegasi, -
    return (c1.real == -c2.real) && (c1.imag == -c2.imag);
}

int isMatrixSame(matrix m1, matrix m2) {
    for (int i=0; i<m1.kol; i++) {
        for (int j=0; j<m1.brs; j++) {
            // Jika ada yang tidak sama, akan dikembalikan langsung nilai 0 karena tidak sama
            if (!isComplexSame(m1.contents[i][j], m2.contents[i][j])) {
                return 0;
            }
        }
    }
    return 1; // Sama semua yey
}
int isMatrixNegated(matrix m1, matrix m2) {
    for (int i=0; i<m1.kol; i++) {
        for (int j=0; j<m1.brs; j++) {
            // Jika ada yang tidak sama, akan dikembalikan nilai 0 karena tidak sama
            if (!isComplexNegated(m1.contents[i][j], m2.contents[i][j])) {
                return 0;
            }
        }
    }
    return 1; // Sama semua yey
}

int main() {
    // KAMUS
    int brs, kol;
    matrix mat;

    // Input
    scanf("%d %d", &brs, &kol);
    inputmatrix(&mat, brs, kol);

    // Pengolahan matriks
    matrix trans = transpose(mat);
    matrix conj  = conjugate(trans);

    // Output
    if (isMatrixSame(mat, conj) && isMatrixNegated(mat, conj)) {
        printf("Matriks merupakan matriks skew hermitian dan matriks hermitian\n");
    }
    else if (isMatrixSame(mat, conj)) {
        printf("Matriks merupakan matriks hermitian\n");
    }
    else if (isMatrixNegated(mat, conj)) {
        printf("Matriks merupakan matriks skew hermitian\n");
    }
    else {
        printf("Matriks bukan merupakan keduanya\n");
    }

    return 0;
}
