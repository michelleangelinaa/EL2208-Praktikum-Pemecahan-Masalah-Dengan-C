/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 6 - Linked List
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Selasa, 23 Maret 2021
 *  Nama File           : lib.h
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Header file untuk library linked list. 
 */

#include <stdio.h>
#include <stdlib.h>

/** Node. Sebuah node dari singly-linked list.
 * 
 * @param data data int yang disimpan dalam node.
 * @param next pointer menuju node berikutnya. 
 */
typedef struct Node { 
    int data; 
    struct Node* next; 
} Node;

/** printLinkedList. Print seluruh isi linked list.
 * 
 * @param current_node pointer menuju node dimulainya print.
 * @result seluruh data yang tersimpan dalam linked list tercetak.
 */
void printLinkedList(Node* current_node);

/** printLinkedListRecursive. Print seluruh isi linked list tapi rekursif.
 * 
 * @param current_node pointer menuju node dimulainya print.
 * @result seluruh data yang tersimpan dalam linked list tercetak.
 */
void printLinkedListRecursive(Node* current_node);

/** push. Tambahkan node berisi new_data di depan linked list.
 * 
 * @param head pointer to pointer to node head dari linked list.
 * @param new_data data yang akan disimpan dalam node baru.
 * @result head menyimpan pointer menuju node paling depan baru yang berisi new_data.
 */
void push(Node** head, int new_data);

/** insert. Tambahkan node berisi new_data setelah prev_node.
 * 
 * @param prev_node pointer menuju node pendahulu node baru.
 * @param new_data data yang akan disimpan dalam node baru.
 * @result node berisi new_data ditambahkan setelah prev_node.
 */
void insert(Node* prev_node, int new_data);

/** deleteNode. Hapus node yang ditunjuk del_node dari linked list.
 * 
 * @param head pointer to pointer to node head dari linked list.
 * @param del_node pointer menuju node yang akan dihapus dari linked list.
 * @result del_node terhapus dari linked list.
 */
void deleteNode(Node** head, Node* del_node);

/** deleteKey. Hapus node pertama yang menyimpan data dengan value key dari linked list.
 * 
 * @param head pointer to pointer to node head dari linked list.
 * @param key data int dari elemen yang ingin dihapus dari linked list.
 * @result elemen pertama yang menyimpan key terhapus dari linked list.
 */
void deleteKey(Node** head, int key);

/** destroy. Hapus seluruh isi linked list.
 * 
 * @param head pointer to pointer to node head dari linked list.
 * @result memori seluruh isi linked list dibersihkan dan *head berisi NULL.
 */
void destroy(Node** head);

/** destroyHelper. Pembantu rekursi untuk destroy.
 * 
 * @param cur_node node yang sedang dihapus saat ini.
 * @result memori cur_node dan seluruh node setelahnya dibersihkan.
 */
void destroyHelper(Node* cur_node);