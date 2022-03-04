/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 3 - Pointers and Functions
*Percobaan        : 02 - https://classroom.github.com/a/mDbHtYR4
*Hari dan Tanggal : Jumat, 4 Maret 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    : Syifa Kushirayati (18319037)
*Nama File        : soal-02.c
*Deskripsi        : Program untuk mengonvolusi sebuah citra berdimensi 5x5. Setiap piksel dari citra memuat
                    informasi kehitaman dari piksel yang direpresentasikan oleh 8 bit integer (rentang: 0-255).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ROW 5
#define INPUT_COLUMN 5
#define FILTER_ROW 3
#define FILTER_COLUMN 3
#define MAX_STRING 200

// Deklarasi variabel
int inputMatrix[INPUT_ROW*INPUT_COLUMN];
float filterMatrix[FILTER_ROW*FILTER_COLUMN];
float outputMatrix[(INPUT_ROW-FILTER_ROW+1)*(INPUT_COLUMN-FILTER_COLUMN+1)];

//----------------------------------- FUNGSI MEMBACA FILE -----------------------------------//
// Deskripsi: mengekstrak informasi dari file eksternal dan menyimpannya ke dalam variabel input dan filter
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
//---------------------------------------------------------------------------------------//
void getMatrix(int *input, float *filter){
	FILE *filePointer ;

	char filename[MAX_STRING];
	char buffer[MAX_STRING];
	char *token;
	int i = 0;
	int isFileExist;

	printf("Masukkan nama file: ");
	scanf("%s", filename);

	filePointer = fopen(filename, "r") ;

	if ( filePointer == NULL )
	{
		printf("File gagal dibuka.\n");
		isFileExist = 0;
	}
	else
	{
		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(input+i) = atoi(token);
			token = strtok(NULL, ",");
			i++;
		}

		i = 0;

		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(filter+i) = atof(token);
			token = strtok(NULL, ",");
			i++;
		}

		fclose(filePointer);
	}

	return;
}

//----------------------------------- FUNGSI KONVOLUSI -----------------------------------//
// Deskripsi: fungsi untuk konvolusi matriks input dengan filter. hasilnya disimpan pada variabel output
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
// *output : pointer matriks output
//---------------------------------------------------------------------------------------//
void convolution(int *input, float *filter, float *output){
    for (int i = 0; i < INPUT_ROW-FILTER_ROW+1; i++) {
        for (int j = 0; j < INPUT_COLUMN-FILTER_COLUMN+1; j++) {
            // Diasumsikan semua file konvolusi yang digunakan adalah input 5x5 dan filter 3x3
            output[i * (INPUT_COLUMN-FILTER_COLUMN+1) + j] = (input[i * (INPUT_COLUMN) + j]*filter[0])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 1]*filter[1])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 2]*filter[2])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 5]*filter[3])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 6]*filter[4])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 7]*filter[5])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 10]*filter[6])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 11]*filter[7])
                                                             + (input[(i * (INPUT_COLUMN) +j)+ 12]*filter[8]);

        }

    }

}

//----------------------------------- FUNGSI OUTPUT -----------------------------------//
// Deskripsi : fungsi untuk mencetak matriks input, filter, dan output
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
// *output : pointer matriks output
//---------------------------------------------------------------------------------------//
void printMatrix(int *input, float *filter, float *output){
	printf("Matriks input: \n");
	for(int row = 0; row < INPUT_ROW; row++){
		for(int col = 0; col < INPUT_COLUMN; col++){
			printf("%d\t", *(input+row*(INPUT_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks filter: \n");
	for(int row = 0; row < FILTER_ROW; row++){
		for(int col = 0; col < FILTER_COLUMN; col++){
			printf("%.2f\t", *(filter+row*(FILTER_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks output: \n");
	for(int row = 0; row < INPUT_ROW-FILTER_ROW+1; row++){
		for(int col = 0; col < INPUT_COLUMN-FILTER_COLUMN+1; col++){
			printf("%.2f\t", *(output+row*(INPUT_COLUMN - FILTER_COLUMN + 1) + col));
		}
		printf("\n");
	}
}

int main(){
    getMatrix(inputMatrix, filterMatrix);
    convolution(inputMatrix, filterMatrix, outputMatrix);
    printMatrix(inputMatrix, filterMatrix, outputMatrix);

    return 0;
}
