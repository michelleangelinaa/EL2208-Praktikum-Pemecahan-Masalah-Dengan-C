/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 6 - Linked List
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Selasa, 23 Maret 2021
 *  Nama File           : linked-list.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Main file untuk tutorial modul 06. 
 */

/** Perintah Kompilasi
 * 
 * Linux/MacOS  - gcc -o linked-list linked-list.c lib.c
 * Windows      - gcc -o linked-list.exe linked-list.c lib.c
 * 
 * atau dengan Makefile:
 * 
 * Linux/MacOS - make
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    // Tambahkan tiga node pertama linked list
    Node* head = (Node*) malloc(sizeof(Node));
    Node* second_node = (Node*) malloc(sizeof(Node));
    Node* third_node = (Node*) malloc(sizeof(Node));

    head->data = 9;
    second_node->data = 6;
    third_node->data = 7;

    head->next = second_node;
    second_node->next = third_node;
    third_node->next = NULL;

    // Print isi linked list, tapi manual
    // Perhatikan bahwa seluruh node bisa diakses hanya dengan
    // mengetahui address dari node head
    printf("%d %d %d \n", head->data, head->next->data, head->next->next->data);

    // Print isi linked list saat ini
    printLinkedList(head);

    // Tambahkan node berisi 420 di depan linked list
    push(&head, 420);
    printLinkedList(head);

    // Tambahkan node berisi 1337 di depan linked list
    insert(second_node, 1337);
    printLinkedList(head);

    // Hapus second_node
    deleteNode(&head, second_node);
    printLinkedList(head);

    // Hapus node pertama yang berisi 9
    deleteKey(&head, 9);
    printLinkedList(head);

    // Hapus node pertama yang berisi 420
    deleteKey(&head, 420);
    printLinkedList(head);

    // Bebaskan memori (ekuivalen dengan free)
    destroy(&head);

    return 0;
}