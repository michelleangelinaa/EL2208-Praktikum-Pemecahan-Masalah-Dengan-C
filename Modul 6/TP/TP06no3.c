#include <stdio.h>
#include <stdlib.h>

// Membentuk linked list berisi 1 data bertipe integer dengan jenis singly linked list
typedef struct node {
   int data;
   struct node *next; // Node pointer
};

// Asumsikan head linked list adalah sebuah NULL
struct node *head = NULL;

// Prosedur insersi jika n adalah elemen paling awal
// https://stackoverflow.com/questions/11260880/adding-a-node-into-a-linked-list-right-after-the-head
void insertfirst(struct node **head, int data1) {
    // Assign new node untuk yang baru
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data1;

    if (newNode) {
        // pointer untuk next
        newNode->next = NULL;

        if (NULL == *head) {
            *head = newNode; // Setting headnya
        }
        else {
            // Memasukkan new node setelah head, dengan variabel temp
            struct node *temp = *head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Prosedur insersi ke n di bagian tengah dan belakang
void insertmid(struct node *head, int data1; int n) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data1;

    struct node *temp = head;
    // Mencari prevnode
    for (int i=1; i<n; i++) { // i = 0 adalah head
        temp = temp->next;
    }

    // Menyisipkan new node
    // Memberikan pointer next prevnode ke new node
    newNode->next = temp->next;
    // Menjadikan pointer next prevnode ke new node
    temp->next = newNode;
}

// Prosedur delesi
// https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
void deletion(struct node *head, int n) {
    // Menghapus node ke-n
    struct node *temp = head; // Dummy
    struct node *temp1 = prev;

    // Mencari prevnode
    for (int i=1; i<n; i++) { // i = 0 adalah head
        temp = temp->next;
    }
    prev =  temp;
    temp = temp->next;

    // Menghapus head yang sudah NULL
    if (temp != NULL) {
        head = temp->next;
        free(temp);
        return;
    }

    prev->next = temp->next;
    free(temp);
}
