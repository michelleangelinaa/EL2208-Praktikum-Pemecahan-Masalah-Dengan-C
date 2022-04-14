/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 7 - Stacks and Queues
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 2 April 2021
 *  Nama File           : stack_lib.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Implementation file untuk library stack.
 */

#include "stack_lib.h"

int isStackEmpty(Stack* stack) { 
    return stack->head == NULL;
}

void push(Stack* stack, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = stack->head;

    stack->head = new_node;
}

int pop(Stack* stack) {
    int ret_val = 0;
    Node* temp = stack->head;

    if (temp != NULL) {
        ret_val = temp->data;
        stack->head = temp->next;

        free(temp);
    }

    return(ret_val);
}

int peek(Stack* stack) {
    if (stack->head != NULL)
        return stack->head->data;
    else
        return 0;
}

void printStack(Stack* stack) {
    Node* current = stack->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}