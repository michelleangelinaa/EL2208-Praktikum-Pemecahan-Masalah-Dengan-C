/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 5 - Recursion
*Percobaan        : 02 - Praktikum
*Hari dan Tanggal : Kamis, 24 Maret 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    : Muhammad Morteza Mudrick (13219061)
*Nama File        : soal-02.c
*Deskripsi        : Program untuk mencari solusi atau akar dari sebuah polinomial dengan metode Newton Raphson
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEN_MAX 255

// Fungsi turunan
float derive(int n, int koefisien[n+1], float x) {
    float hasilderiv = 0;
    int degree = n;

    for (int i = 0; i < degree; i++) {
        // KESALAHAN: Array of koefisien yang ada ternyata sudah berkebalikan, dimulai dari koefisien konstanta baru ke koefisien derajat tertinggi
        hasilderiv += koefisien[degree-i] * (degree-i) * pow(x, (degree - (i+1))); // Untuk perhitungan turunan polinomial
    }

    return hasilderiv;
}

// Fungsi polinomial
float poly(int n, int koefisien[n+1], float x) {
    float hasilpoly = 0;
    int degree = n;

    for (int i = degree; i >= 0; i--) {
        // KESALAHAN: Array of koefisien yang ada ternyata sudah berkebalikan, dimulai dari koefisien konstanta baru ke koefisien derajat tertinggi
        hasilpoly += koefisien[i] * pow(x, i); // Untuk fungsi polinomial
    }

    return hasilpoly;
}

// Fungsi untuk menghitung metode Newton Raphson
void newraph(int n, int koefisien[n+1], float *xn) {
    float xnew;
    if (poly(n, koefisien, *xn) != 0) { // Jika f(x_n) belum nol akan terus rekursi
        // Rumus
        xnew = *xn - poly(n, koefisien, *xn)/derive(n, koefisien, *xn);
        *xn = xnew; // Overwrite
        newraph(n, koefisien, xn);
    }

}

int main(){
	//template input
	int degree;
	int *coef = (int*) malloc (sizeof(int));
	float hasil;
	float xn = 0;

	// Masukkan derajat polinom
	printf("Masukkan derajat polinom: ");
	scanf("%d",&degree);

	// Ubah ukuran array derajat polinom
	coef = realloc(coef,((degree)+1)*sizeof(int));

	// Input string koefisien polinom
	printf("Masukkan koefisien polinom: ");
	char coef_str[LEN_MAX];
	char* token;
	scanf("%s",coef_str);

	int i = degree;
	token = strtok(coef_str,",");
	while(token != NULL){
		coef[i] = atoi(token);
		i -= 1;
		token = strtok(NULL,",");
	}

	// Rumus perhitungan mencari akar-akar x
	// x_n+1 = x_n - f(x_n)/f'(x_n)
	// Iterasi sampai f(x_n) = 0 atau x_n+1 = x_n
	newraph(degree, coef, &xn);

	// Format print untuk autograder
	printf("Akar polinom bersangkutan yang paling dekat dengan 0 adalah %.2f", xn);

	return 0;
}
