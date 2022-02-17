# Modul 0: Hello, World!
Modul 0 ini memiliki tujuan untuk mengenalkan dan membiasakan praktikan dengan *workflow* GitHub Classroom.

## Instruksi
Buatlah program yang dapat mencetak `Hello, World!` saat dieksekusi.
Silakan ubah isi *file* `hello.c` agar dapat menampilkan `Hello, World!`, kemudian lakukan *commit* dan *push* perubahan tersebut ke branch `main` dari *repository* anda.

### Hint
Anda dapat mengerjakan dengan salah satu metode berikut:  
1. Melakukan `clone` *repository* ini ke komputer anda, mengubah *source code* secara *offline*, kemudian melakukan `commit` dan `push` ke *branch* `main`, atau
2. Mengunduh *repository* ini, mengubah *source code* secara *offline*, kemudian mengunggah *file* ke web GitHub dan melakukan `commit` ke *branch* `main`, atau
3. Mengubah *source code* secara langsung di web GitHub, kemudian melakukan `commit` ke *branch* `main`.  

## Perintah Kompilasi
Perhatikan bahwa *autograder* bekerja dengan sistem operasi Linux sehingga proses kompilasi juga disesuaikan dengan sistem operasi tersebut. *Compiler* yang digunakan dalam praktikum ini adalah `gcc`.

Proses kompilasi dilakukan dengan memanfaatkan `Makefile`. Secara sederhana `Makefile` merupakan file yang berisi kode kompilasi yang sudah diperpendek. Perintah kompilasi yang digunakan adalah

```sh
make hello
```

Perintah tersebut dapat langsung dijalankan pada terminal apabila anda tidak menggunakan *file eksternal* lainnya (sudah teruji pada `bash` Linux Ubuntu 20.04).

### Penjelasan Makefile
`Makefile` yang terdapat pada *repository* ini berarti:
1. Perintah `make hello` akan mengeksekusi perintah `gcc -o hello hello.c -lm` pada baris kedua yang berfungsi untuk melakukan kompilasi *file* `hello.c` dengan *compiler* `gcc` pada *file output* `hello`.
2. Perintah `make clean` akan mengeksekusi perintah `rm hello` pada baris kedua yang berfungsi untuk menghapus file `hello` yang telah terkompilasi sebelumnya.

Apabila anda menggunakan *file eksternal* lainnya, silakan melakukan penyesuaian pada *file* `Makefile` pada bagian `make hello` yakni dengan menambahkan perintah `gcc -o hello hello.c (file eksternal) -lm`, ubah (file eksternal) dengan nama file yang anda gunakan.

## Perintah Run
Perhatikan bahwa *autograder* bekerja dengan sisten operasi Linux sehingga proses *run* juga disesuaikan dengan sistem operasi tersebut.

Perintah *run* yang digunakan adalah

```sh
./hello
```
Perintah tersebut sudah teruji pada `bash` Linux Ubuntu 20.04.
