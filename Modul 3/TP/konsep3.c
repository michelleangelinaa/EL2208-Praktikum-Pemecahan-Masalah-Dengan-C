/*#include <stdio.h>

int main(){
	int *p1;
	int **p2; // Sebenarnya tidak perlu double pointer di kode ini, double pointer biasanya digunakan untuk array dua dimensi
	// p2 akan mengambil address dari p1, bukan address c
	int c = 4;
	
	p1 = &c;
	p2 = &c;

	c = *p1 * &c * p2; // & digunakan untuk mengambil address dari c, bukan nilai c, jadi program akan mengeluarkan error
	// pointer yang ingin dieksekusi harus menggunakan * supaya program mengambil isi dari pointer tersebut, bukan addressnya
	// Karena p2 adalah double pointer, diperlukan **p2 supaya program mengambil nilai dari p2, bukan addressnya
	
	return 0;
}*/

#include <stdio.h>

int main(){
	int *p1;
	int **p2;
	int c = 4;
 
	p1 = &c; // Jika *p1 = c, maka p1 = &c, *p1 adalah nilai, &c adalah addressnya, dengan kata lain, p1 adalah address dan *p1 adalah nilainya
	p2 = &c;
	c = *p1 * c * (**p2); // *p1 = 4 dikali c = 4 dikali **p2 = 4 = 64
	return 0;
}

int *b; // Pointer menuju b
int al = 6; // al bernilai 6, b belum bernilai
b = &al; // al bernilai 6 dan b bernilai 6
al = 10; // al bernilai 10 dan b bernilai 10
