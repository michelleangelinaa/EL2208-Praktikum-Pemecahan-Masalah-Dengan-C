/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 7 - Stacks and Queues
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 2 April 2021
 *  Nama File           : common.h
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Common header file untuk library stack dan queue.
 */

/** Node. Sebuah node dari singly-linked list.
 * Digunakan sebagai elemen dari Stack dan Queue.
 * 
 * @param data data int yang disimpan dalam node.
 * @param next pointer menuju node berikutnya. 
 */
typedef struct Node { 
    int data; 
    struct Node* next; 
} Node;