/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 7 - Stacks and Queues
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 2 April 2021
 *  Nama File           : queue_lib.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Implementation file untuk library queue.
 */

#include "queue_lib.h"

int isQueueEmpty(Queue* queue) {
    return queue->head == NULL;
}

void enqueue(Queue* queue, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (!isQueueEmpty(queue)) {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    else {
        queue->tail = new_node;
        queue->head = new_node;
    }
}

int dequeue(Queue* queue) {
    int ret_val = 0;
    Node* temp = queue->head;

    if (temp != NULL) {
        ret_val = temp->data;
        queue->head = temp->next;

        if (temp == queue->tail)
            queue->tail = NULL;
        
        free(temp);
    }

    return ret_val;
}

int front(Queue* queue) {
    if (!isQueueEmpty(queue))
        return queue->head->data;
    else
        return 0;
}

int rear(Queue* queue) {
    if (!isQueueEmpty(queue))
        return queue->tail->data;
    else
        return 0;
}

void printQueue(Queue* queue) {
    Node* current = queue->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}