/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 5 - Recursion
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 19 Maret 2021
 *  Nama File           : tutorial-05.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Source code tutorial untuk modul 05, materi rekursi.
 */

/** Perintah Kompilasi
 * 
 * Linux/MacOS  - gcc -o tutorial-05 tutorial-05.c
 * Windows      - gcc -o tutorial-05.exe tutorial-05.c
 * 
 * atau dengan Makefile:
 * 
 * Linux/MacOS - make all
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

/** recursive_power. Hitung pangkat bilangan bulat secara rekursif.
 * 
 * @param[in] num Bilangan bulat yang akan dipangkatkan.
 * @param[in] pow Bilangan bulat positif pangkat.
 * @return Hasil dari num pangkat pow.
 */
int recursive_power(int num, int pow);

/** recursive_print. Print isi array secara rekursif.
 * 
 * @param[in] arr Array of integer yang akan dicetak, diberikan sebagai pointer.
 * @param[in] size Bilangan bulat ukuran arr.
 * @param[in] cur_idx Indeks yang sedang dicetak saat ini.
 * @result Seluruh isi arr tercetak ke layar.
 */
void recursive_print(int *arr, int size, int cur_idx);

/** check_palindrome. Cek apakah suatu string merupakan palindrom.
 * 
 * @param[in] s String yang akan diperiksa sifat palindromnya.
 * @return Apakah s merupakan palindrom.
 */
int check_palindrome(char *s);

/** check_palindrome_helper. Fungsi pembantu rekursi check_palindrome.
 * 
 * @param[in] s String yang akan diperiska sifat palindromnya.
 * @param[in] idx_front Bilangan bulat indeks karakter depan yang sedang diperiksa.
 * @param[in] idx_rear Bilangan bulat indeks karakter belakang yang sedang diperiksa.
 * @return Apakah s merupakan palindrom.
 */
int check_palindrome_helper(char *s, int idx_front, int idx_rear);

int main() {
    // Bagian 1 - Hitung pangkat bilangan bulat
    // Ubah dua variabel berikut untuk mencoba-coba.
    // num - bilangan bulat yang dipangkatkan
    int num = 2;
    // pow - bilangan bulat positif pangkatnya
    int pow = 10;

    printf("\nHitung pangkat: \n");
    printf("Hasil dari %d pangkat %d adalah: %d\n", num, pow, recursive_power(num, pow));

    // Bagian 2 - Print array secara rekursif
    // Ubah arr untuk mencoba-coba.
    int arr[] = {0, 1, 2, 3, 4, 5};

    printf("\nPrint rekursif: \n");
    recursive_print(arr, sizeof(arr) / sizeof(arr[0]), 0);

    // Bagian 3 - Periksa palindrom
    // Ubah s untuk mencoba-coba.
    char* s = "kasurrusak";

    printf("\nCek palindrom: \n");
    if (check_palindrome(s))
        printf("'%s' adalah palindrome.\n", s);
    else
        printf("'%s' bukan palindrom.\n", s);

    return 0;
}

int recursive_power(int num, int pow) {
    // Kasus basis, apabila pangkat sudah sama dengan nol
    if (pow == 0)
        return 1;
    else
        // Rekuren, kalikan num dengan num^(pow -1)
        return num * recursive_power(num, pow - 1);
}

void recursive_print(int *arr, int size, int cur_idx) {
    // Rekuren, print elemen sekarang dan selanjutnya
    if (cur_idx < size) {
        printf("%d ", arr[cur_idx]);
        
        recursive_print(arr, size, cur_idx + 1);
    }
    else
        // Kasus basis, ketika cur_idx == size, print newline
        printf("\n");
}

int check_palindrome(char *s) {
    // Fungsi ini dibuat hanya agar kita bisa memanggil fungsi
    // periksa palindrom tanpa memberikan indeks-indeks.

    // Panggil fungsi check_palindrome_helper dengan idx_front 0 dan
    // idx_rear elemen paling belakang string.
    return check_palindrome_helper(s, 0, strlen(s) - 1);
}

int check_palindrome_helper(char *s, int idx_front, int idx_rear) {
    // Kasus basis bila panjang ganjil
    if (idx_front == idx_rear)
        return 1;

    // Kasus basis bila panjang genap
    if (idx_front == idx_rear - 1 && s[idx_front] == s[idx_rear])
        return 1;

    // Rekuren, bila belum sampai ke tengah, cek bagian tengahnya
    if (s[idx_front] != s[idx_rear])
        // Bila ditemukan pasangan karakter yang berbeda, langsung
        // nyatakan bahwa s bukan palindrom.
        return 0;
    else
        // Bila masih sama, cek pasangan karakter selanjutnya (ke tengah)
        return check_palindrome_helper(s, idx_front + 1, idx_rear - 1);
}
