#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nim;
    int nilai;
    struct Node* next;
} Node;

/*
* fungsi untuk menambah data ke dalam linked list
*
* @param head: pointer to pointer to head Node ke linked list
* @param nim: NIM mahasiswa
* @param nilai: nilai mahasiswa
*/
void add(Node **head, int nim, int nilai) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    // Pembentukan Node baru dari pengguna
    newNode->nim = nim; //Memasukkan NIM
    newNode->nilai = nilai; // Memasukkan nilai mahasiswa
    newNode->next = NULL; // pointer ke NULL untuk pengisian pertama

    // Berikan Node pertama sebagai head linked list
    if (*head == NULL) {
        *head = newNode;
    }
    // Untuk Node-Node selanjutnya
    // https://www.log2base2.com/data-structures/linked-list/inserting-a-Node-at-the-end-of-a-linked-list.html
    else {
        Node *prev = *head;

        while (prev->next != NULL) {
            prev = prev->next;
        }
        prev->next = newNode;
    }
}

/*
* fungsi untuk mencetak data dari linked list
*
* @param head: pointer to head Node ke linked list
*/
void print(Node* head) {
    // https://www.opentechguides.com/how-to/article/c/141/linkedlist-add-del-print-count.html
    while (head != NULL) { // Berakhir saat menemukan NULL di linked list
        printf("NIM: %d, Nilai: %d", head->nim, head->nilai);
        printf("\n");
        // Overwrite, diprint sesuai sekuens
        head = head->next;
    }
}

/*
* fungsi untuk mencari data nilai tertinggi dari linked list kemudian mencetak
nilainya
*
* @param head: pointer to head Node ke linked list
*/
void searchMax(Node* head) {
    // Dummy
    int max_nilai = -1; // Asumsikan nilai mahasiswa tidak pernah mencapai -1
    int max_nim = 0;

    while (head != NULL) {
        if (max_nilai < head->nilai) { // Ada yang lebih besar akan dioverwrite
            max_nilai = head->nilai;
            // Karena tidak bisa menggunakan indeks, NIMnya juga harus tercatat di sebuah variabel
            max_nim = head->nim;
        }
        head = head->next; // Selanjutnya
    }
        // Print
        printf("Nilai tertinggi:\n");
        printf("NIM: %d, Nilai: %d\n", max_nim, max_nilai);
}

/*
* fungsi untuk mencari data nilai terendah dari linked list kemudian mencetak
nilainya
*
* @param head: pointer to head Node ke linked list
*/
void searchMin(Node* head) {
    // Dummy
    int min_nilai = 200; // Asumsikan nilai mahasiswa tidak pernah mencapai 200
    int min_nim = 0;

    while (head != NULL) {
        if (min_nilai > head->nilai) { // Ada yang lebih besar akan dioverwrite
            min_nilai = head->nilai;
            // Karena tidak bisa menggunakan indeks, NIMnya juga harus tercatat di sebuah variabel
            min_nim = head->nim;
        }
        head = head->next; // Selanjutnya
    }
        // Print
        printf("Nilai terendah:\n");
        printf("NIM: %d, Nilai: %d\n", min_nim, min_nilai);
}

int main() {
    Node* head = NULL;

    add(&head, 10018001,90);
    add(&head, 10018002,80);
    add(&head, 10018003,68);
    add(&head, 10018004,89);
    add(&head, 10018005,92);
    add(&head, 10018006,80);

    print(head);
    searchMax(head);
    searchMin(head);

    free(head);
    return 0;
}
