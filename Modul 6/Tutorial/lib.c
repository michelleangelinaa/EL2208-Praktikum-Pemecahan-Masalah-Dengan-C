/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 6 - Linked List
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Selasa, 23 Maret 2021
 *  Nama File           : lib.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Source file untuk library linked list. 
 */

#include "lib.h"

void printLinkedList(Node* current_node) {
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void printLinkedListRecursive(Node* current_node) {
    if (current_node != NULL) {
        printf("%d ", current_node->data);
        printLinkedList(current_node->next);
    }
}

void push(Node** head, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void insert(Node* prev_node, int new_data) {
    if (prev_node != NULL) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

void deleteNode(Node** head, Node* del_node) {
    Node* cur_node = *head;
    Node* prev_node;

    if (del_node == *head) {
        *head = (*head)->next;
        free(cur_node);
    }
    else {
        while (cur_node != del_node && cur_node != NULL) {
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
        if (cur_node != NULL) {
            prev_node->next = cur_node->next;
            free(cur_node);
        }
    }
}

void deleteKey(Node** head, int key) {
    Node* cur_node = *head;
    Node* prev_node;

    if ((*head)->data == key) {
        *head = (*head)->next;
        free(cur_node);
    }
    else {
        while (cur_node->data != key && cur_node != NULL) {
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
        if (cur_node != NULL) {
            prev_node->next = cur_node->next;
            free(cur_node);
        }
    }
}

void destroyHelper(Node* cur_node) {
    if (cur_node != NULL) {
        destroyHelper(cur_node->next);
        free(cur_node);
    }
}

void destroy(Node** head) {
    destroyHelper(*head);
    *head = NULL;
}