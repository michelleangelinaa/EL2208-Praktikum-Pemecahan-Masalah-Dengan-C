/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : Praktikum
*Hari dan Tanggal : Kamis, 31 Maret 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    : Dhanurangga Al Fadh (13218005)
*Nama File        : soal-01.c
*Deskripsi        : Program yang dapat menggabungkan ketiga linked list kecil menjadi sebuah linked list besar dengan isi data integer yang tetap dalam urutan meningkat
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Struct Node Linked List
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// Menambahkan node ke linked list
// REFERENSI: Diambil dari jawaban soal pemrograman Tugas Pendahuluan Modul 06
void insert(Node **head, int element) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    // Pembentukan Node baru dari pengguna
    newNode->data = element; //Memasukkan angka - angkanya ke linked list
    newNode->next = NULL; // pointer ke NULL untuk pengisian pertama

    // Berikan Node pertama sebagai head linked list
    if (*head == NULL) {
        *head = newNode;
    }
    // Untuk Node-Node selanjutnya
    else {
        Node *prev = *head;

        while (prev->next != NULL) {
            prev = prev->next;
        }
        prev->next = newNode;
    }
}

// Prosedur untuk output
// REFERENSI: Diambil dari jawaban soal pemrograman Tugas Pendahuluan Modul 06
void print(Node* head) {
    while (head != NULL) { // Berakhir saat menemukan NULL di linked list
        printf("%d ", head->data);
        // Overwrite, diprint sesuai sekuens
        head = head->next;
    }
}

// Melakukan merge dan sort dua buah linked list
// REFERENSI: https://iq.opengenus.org/merge-two-sorted-linked-lists/
struct Node *merge(struct Node *head1, struct Node *head2) {
    // Hasil akhirnya
    struct Node *merged = NULL;

    // Pembandingan antar head linked list
    // Jika data dalam linked list 1 lebih kecil dari linked list 2, Node merged akan ditambahkan karena yang terkecil
    if (head1->data <= head2->data) {
        merged = head1;
        // Kemudian head1 akan bergeser
        head1 = head1->next;
    }
    else {
        // Data dalam head2 lebih kecil dari head1, masuk duluan ke merged
        merged = head2;
        // Kemudian head2 akan bergeser
        head2 = head2->next;
    }

    // Temporary
    struct Node *temp = merged;

    // Selama belum bertemu dengan NULL, yaitu node terakhir dalam setiap linked list, akan terjadi loop
    while (head1 != NULL && head2 != NULL) {
        // Temporary
        Node *dummy = NULL;
        // Jika data dalam linked list 1 lebih kecil dari linked list 2, Node merged akan ditambahkan karena yang terkecil
        if (head1->data <= head2->data) {
            dummy = head1;
        // Kemudian head1 akan bergeser
            head1 = head1->next;
        }
        else {
            dummy = head2;
        // Kemudian head2 akan bergeser
            head2 = head2->next;
        }

        // Masukkan Node dummy ke temp, yang akan masuk ke merged
        temp->next = dummy;
        temp = dummy;

    }

    // Penggeseran
    if (head1 != NULL) {
        temp->next = head1;
    }
    else if (head2 != NULL) {
        temp->next = head2;
    }

    return merged;
}

// Penggunaan free untuk linked list, penggunaan fungsi free tidak bisa dilakukan sekali sehingga harus menggunakan rekursif
// REFERENSI: https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
// REFERENSI: Tutorial Modul 06, nama file: lib.c
/*
void destroy(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
       temp = head;
       head = head->next;
       free(temp);
    }
}
*/

int main()
{
    /* CATATAN
    - Ketiga linked list tidak boleh kosong
    - Ketiga linked list harus berisikan sejumlah integer yang sudah tersusun meningkat
    */

    // KAMUS
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    Node *headhalf = NULL;
    Node *headfull = NULL;

    int n1, n2, n3, element, i;

    // INPUT
	//input linked list pertama
	printf("Masukkan jumlah elemen linked list pertama: ");
	scanf("%d", &n1);

	printf("Masukkan elemen-elemen linked list pertama: ");
	for (i=0; i<n1; i++) {
        scanf("%d", &element);
        insert(&head1, element);
	}

	//input linked list kedua
	printf("Masukkan jumlah elemen linked list kedua: ");
	scanf("%d", &n2);

	printf("Masukkan elemen-elemen linked list kedua: ");
	for (i=0; i<n2; i++) {
        scanf("%d", &element);
        insert(&head2, element);
	}

	//input linked list ketiga
	printf("Masukkan jumlah elemen linked list ketiga: ");
	scanf("%d", &n3);

	printf("Masukkan elemen-elemen linked list ketiga: ");
	for (i=0; i<n3; i++) {
        scanf("%d", &element);
        insert(&head3, element);
	}

    headhalf = merge(head1, head2);
    headfull = merge (headhalf, head3);

	// OUTPUT
	//Cetak output berupa urutan integer
	printf("\nHasil urutan gabungan ketiga linked list: ");
	print(headfull);

	// Tetap error meskipun menggunakan fungsi destroy
	/*
    destroy(head1);
    destroy(head2);
    destroy(head3);
    destroy(headhalf);
    destroy(headfull);
    */

	return 0;
}
