/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 7 - Stacks and Queues
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 2 April 2021
 *  Nama File           : stack_lib.h
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Header file untuk library stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/** Stack. Representasi dari sebuah stack.
 * 
 * @param head pointer menuju node paling atas dalam stack.
 */
typedef struct Stack {
    Node* head;
} Stack;

/** push. Tambahkan new_data ke atas stack.
 * 
 * @param stack pointer menuju stack.
 * @param new_data data baru untuk ditambahkan ke dalam stack.
 */
void push(Stack* stack, int new_data);

/** pop. Hapus elemen paling atas dari stack, ambil datanya.
 * 
 * @param stack pointer menuju stack.
 * @return stack->head->data bila ada, 0 bila tidak ada.
 */
int pop(Stack* stack);

/** peek. Lihat data elemen paling atas dari stack.
 * 
 * @param stack pointer menuju stack.
 * @return stack->head->data bila ada, 0 bila tidak ada.
 */
int peek(Stack* stack);

/** isStackEmpty. Cek apakah stack kosong.
 * 
 * @param stack pointer menuju stack.
 * @return stack->head == NULL.
 */
int isStackEmpty(Stack* stack);

void printStack(Stack* stack);