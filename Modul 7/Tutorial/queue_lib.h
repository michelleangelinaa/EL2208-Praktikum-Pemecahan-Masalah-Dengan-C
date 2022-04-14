/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 7 - Stacks and Queues
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 2 April 2021
 *  Nama File           : queue_lib.h
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Header file untuk library queue.
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/** Queue. Representasi dari sebuah Queue.
 * 
 * @param head pointer menuju node paling depan dalam queue.
 * @param tail pointer menuju node paling belakang dalam queue.
 */
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

/** enqueue. Tambahkan new_data ke belakang queue.
 * 
 * @param queue pointer menuju queue.
 * @param new_data data baru untuk ditambahkan ke dalam queue.
 */
void enqueue(Queue* queue, int new_data);

/** Dequeue. Hapus elemen paling depan dari queue, ambil datanya.
 * 
 * @param queue pointer menuju queue.
 * @return queue->head->data bila ada, 0 bila tidak.
 */
int dequeue(Queue* queue);

/** isQueueEmpty. Cek apakah queue kosong.
 * 
 * @param queue pointer menuju queue.
 * @return queue->head == NULL.
 */
int isQueueEmpty(Queue* queue);

/** front. Ambil data elemen paling depan dari queue.
 * 
 * @param queue pointer menuju queue.
 * @return queue->head->data bila ada, 0 bila tidak.
 */
int front(Queue* queue);

/** rear. Ambil data elemen paling belakang dari queue.
 * 
 * @param queue pointer menuju queue.
 * @return queue->tail->data bila ada, 0 bila tidak.
 */
int rear(Queue* queue);

void printQueue(Queue* queue);