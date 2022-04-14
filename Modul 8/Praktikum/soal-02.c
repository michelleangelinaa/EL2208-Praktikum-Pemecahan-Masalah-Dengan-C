/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 8 - Advanced Algorithms
*Percobaan        : Praktikum
*Hari dan Tanggal : Kamis, 14 April 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    : Syifa Kushirayati (18319037)
*Nama File        : soal-02.c
*Deskripsi        : Sebuah program dalam bahasa C yang menampilkan susunan bidak catur yang mungkin dan
                    menerima input berupa file eksternal yang berisi data ukuran papan catur,
                    jumlah kuda, serta koordinat masing-masing kuda. Program menampilkan keluaran berupa jumlah ratu
                    maksimal yang dapat diletakkan di papan catur serta konfigurasi papan catur yang bersangkutan.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 255

// Silahkan tambahkan fungsi sesuai kebutuhan
// Apabila menggunakan VS Code, tahan tombol Ctrl lalu arahkan ke fungsi untuk melihat deskripsi fungsi

/** @brief fungsi digunakan untuk menampilkan papan catur ke layar
 * @param dim dimensi dari papan catur
 * @param matrix pointer to pointer of char dari papan catur
**/
void print_papan_catur(int dim, char **matrix){
	// Fungsi digunakan untuk menampilkan papan catur ke layar
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}
}

/** @brief fungsi digunakan untuk mengatur ulang papan catur menjadi sesuai bacaan awal dari file eksternal
 * @param dim dimensi dari papan catur
 * @param matrix pointer to pointer of char dari papan catur
**/
void reset_papan_catur(int dim, char **matrix){
	// Fungsi digunakan untuk menghapus ratu yang telah diletakkan di papan catur
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(matrix[i][j]=='Q'){
				matrix[i][j]='X';
			}
		}
	}
}

/** @brief fungsi digunakan untuk menyalin papan catur ke sebuah variabel lain
 * @param dim dimensi dari papan catur
 * @param matrix pointer to pointer of char dari papan catur
 * @param matrix_new pointer to pointer of char dari variabel baru yang akan menjadi tujuan
**/
void salin_papan_catur(int dim, char **matrix, char** matrix_new){
	// Fungsi digunakan untuk menyalin papan catur ke variabel lain
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			matrix_new[i][j] = matrix[i][j];
		}
	}
	return;
}

/** @brief fungsi digunakan untuk membuat papan catur berdasarkan file eksternal
 * @param n_catur pointer to integer dari dimensi dari papan catur
 * @param n_kuda pointer to integer dari jumlah kuda
 * @return pointer to pointer of char dari papan catur
**/
char** buat_papan_catur(int* n_catur, int* n_kuda){
	// Deklarasi variabel
	char file_name[MAX_STRING];
	char each_line[MAX_STRING];
	char temp[MAX_STRING];
	char *token;
	int count = 0;

	// Input nama file
	printf("Masukkan nama file data papan catur: ");
	scanf("%s", file_name);

	// Buka File Eksternal
	FILE* file_catur = fopen(file_name, "r") ;
	// printf("Nama File: %s\n",file_name); // Untuk Debugging

	// Validasi File
	if(file_catur == NULL){
		printf("File tidak dapat dibuka. Program Berakhir.\n");
		fclose(file_catur);
		exit(1);
	}

	// Baca ukuran papan catur
	fgets(each_line,MAX_STRING,file_catur);
	*n_catur = atoi(each_line);

	// Buat bidak catur
	char** catur = (char**) malloc ((*n_catur)*sizeof(char*));
	for(int i=0;i<*n_catur;i++){
		catur[i] = (char*) malloc ((*n_catur)*sizeof(char));
		for(int j=0;j<*n_catur;j++){
			catur[i][j] = 'X';
		}
	}
	// Baca Banyak Kuda
	fgets(each_line,MAX_STRING,file_catur);
	*n_kuda = atoi(each_line);

	// Baca Koordinat Kuda
	while(fgets(each_line,MAX_STRING,file_catur)){
		strcpy(temp,each_line);
		int column = 0,row_temp = 0;
		token = strtok(temp,",");
		while(token!=NULL){
			if(column == 0){
				row_temp = atoi(token);
			}
			else{
				catur[row_temp][atoi(token)] = 'K';
			}
			column += 1;
			token = strtok(NULL,",");
		}
	}
	return catur;
}

// Fungsi recreate catur, copy
char **newboard(int size) {
    // REFERENSI: https://stackoverflow.com/questions/8415537/c-creating-a-matrix-using-pointers-and-then-copying-elements-from-the-matrix
    char **newcatur = (char**) malloc((size)* sizeof(char*));
    for (int i=0; i<size; i++) {
        newcatur[i] = (char*) malloc((size)* sizeof(char)); // Pembuatan catur dengan ukuran yang sama dengan ukuran catur input
        for (int j=0; j<size; j++) {
            newcatur[i][j] = 'X';
        }
    }

    return newcatur;
}

// Fungsi untuk mengecek apakah indeks berada di jangkauan ukuran catur
int valid_index(int size, int i, int j) {
    return (i>=0 && i<size && j>=0 && j<size);
}

int queen_aman_ga(char** catur, int size, int i, int j) {
    int m, n;
    // Untuk petak yang sudah terisi
    if (catur[i][j] != 'X') {
        // Out
        return 0;
    }

    // Queen dengan queen lain tidak boleh saling menyerang, validasi keamanan queen dari queen lain jika ada
    for (m=0; m<size; m++) {
        for (n=0; n<size; n++) {
            // Misalkan queen terletak di [i][j], tidak perlu cek petak m == i dan n == j
            if (!(m == i && n == j)) {
                // Jika ada Q atau K yang menempati, akan langsung diskip
                if ((m == i || n == j || (abs(m-i) == abs(n-j)))
                && (catur[m][n] == 'Q' || catur[m][n] == 'K')) {
                    return 0;
                }
            }
        }
    }

    // Aman dari kuda?
    // Pola serangan kuda, kombinasi operasi index +-, dikombinasikan dengan 1,2
    // 8 petak serangan kuda
    int x[8];
    int y[8];
    x[0] = i+1;
    y[0] = j+2;

    x[1] = i+2;
    y[1] = j+1;

    x[2] = i+1;
    y[2] = j-2;

    x[3] = i-2;
    y[3] = j+1;

    x[4] = i-1;
    y[4] = j+2;

    x[5] = i+2;
    y[5] = j-1;

    x[6] = i-1;
    y[6] = j-2;

    x[7] = i-2;
    y[7] = j-1;

    int index;
    for (index=0; index<8; index++) {
        if (valid_index(size, x[index], y[index]) && catur[x[index]][y[index]] == 'K') {
            return 0;
        }
    }
    catur[i][j] = 'Q';

    return 1;
}

// Fungsi untuk menyelesaikan masalah hidup
void ans(char** catur, int size, char** solution, int q_count, int *n_ratu) {
    int i, j;
    char** catur_cpy = newboard(size);

    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            salin_papan_catur(size, catur, catur_cpy);
            if (queen_aman_ga(catur_cpy, size, i, j)) {
                if (q_count+1 >= *n_ratu) {
                    salin_papan_catur(size, catur_cpy, solution);
                    *n_ratu = q_count+1;
                }
            ans(catur_cpy, size, solution, q_count+1, n_ratu);
            }
        }
    }
    return;
}

int main(){
	int n_catur, n_kuda, n_ratu;
	char** catur;
	n_ratu = 0;

	catur = buat_papan_catur(&n_catur,&n_kuda);
	printf("Konfigurasi papan catur yang diberikan oleh Fei adalah:\n");
	print_papan_catur(n_catur,catur);

	// REFERENSI: https://www.goeduhub.com/9932/implement-n-queens-problem-using-back-tracking-in-c
	// REFERENSI: https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

	// Petak catur untuk jawaban
	char **catur_ans = newboard(n_catur);

	salin_papan_catur(n_catur, catur, catur_ans);
	ans(catur, n_catur, catur_ans, 0, &n_ratu);

	printf("Jumlah pion ratu terbanyak yang dapat diletakkan di papan catur adalah %d ratu.\n", n_ratu);
	printf("Susunan akhir papan catur adalah:\n");
    print_papan_catur(n_catur, catur_ans);

	free(catur);

	return 0;
}


/* Test case: 1. 1,
              2. 4,
              3. 2,
              4. 0,
              5. 5,
              6. 0,
              7. 2,
              8. 4,
              9. 10,
              10. 0.
*/
