/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 7 - Stacks and Queues
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 2 April 2021
 *  Nama File           : tutorial-07-queue.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Source code tutorial untuk modul 07, materi queue.
 */

/** Perintah Kompilasi
 * 
 * Linux/MacOS  - gcc -o tutorial-07-queue tutorial-07-queue.c queue_lib.c
 * Windows      - gcc -o tutorial-07-queue.exe tutorial-07-queue.c queue_lib.c
 * 
 * atau dengan Makefile:
 * 
 * Linux/MacOS - make queue
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue_lib.h"

int main() {

    // Catatan:
    //  dequeue tidak harus return 0 ketika queue
    //  kosong. Pada contoh ini dibuat demikian 
    //  agar lebih mudah dipahami.
    //  anda bisa mengganti 0 dengan INT_MIN misalnya.

    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Front of queue: %d\n", front(queue));
    printf("Rear of queue: %d\n", rear(queue));
    printf("Current queue content:\n");
    printQueue(queue);

    printf("\nDequeue, got: %d\n", dequeue(queue));
    printf("Front of queue: %d\n", front(queue));
    printf("Rear of queue: %d\n", rear(queue));
    printf("Queue content post-dequeue:\n");
    printQueue(queue);

    printf("\nDequeue, got: %d\n", dequeue(queue));
    printf("Front of queue: %d\n", front(queue));
    printf("Rear of queue: %d\n", rear(queue));
    printf("Queue content post-dequeue:\n");
    printQueue(queue);

    printf("\nDequeue, got: %d\n", dequeue(queue));
    printf("Front of queue: %d\n", front(queue));
    printf("Rear of queue: %d\n", rear(queue));
    printf("Queue content post-dequeue:\n");
    printQueue(queue);

    free(queue);

    return 0;
}
