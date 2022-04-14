/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 7 - Stacks and Queues
*Percobaan        : Praktikum
*Hari dan Tanggal : Kamis, 7 April 2022
*Nama (NIM)       : Michelle Angelina (18320007)
*Asisten (NIM)    : Agape D'Sky (13219010)
*Nama File        : soal-01.c
*Deskripsi        : program yang dapat menerima input beberapa bilangan positif. Kemudian, program harus
                    memeriksa sekumpulan angka yang telah dimasukkan oleh user tersebut apakah koprima atau tidak. Jika ya akan dicari KPKnya untuk mengganti bilangan yang tak koprima.
*/

#include <stdio.h>
#include <stdlib.h>

// tipe data simulasi stack
//Struct Node Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

// deklarasi variabel awal
int pop(Stack* stack);
void push(Stack* stack, int new_data);
void printStack(Stack *x); //silakan sesuaikan tipe data stack dengan yang anda gunakan
int coprime(int x, int y);
int lcm(int x, int y);
int gcd(int x, int y);

// fungsi utama
int main(){
    // deklarasi stack input dan output
    // KAMUS
    Stack stacknya;
    stacknya.head = NULL;
    // Stack dummy untuk menampung
    Stack tempStack;
    tempStack.head = NULL;

    int n = -1;
    int i = 1;

    // while loop untuk mengambil input angka dari user
    // loop berhenti bila user memberi input 0
    while (n != 0) {
        printf("Input angka ke-%d: ", i);
        // Asumsikan input selalu positif
        scanf("%d", &n);
        if (n == 0) {
            // angka 0 tidak dimasukkan
            break;
        }
        // Input ke stack
        push(&stacknya, n);
        i++;
    }

    printf("\n");

    // menampilkan stack input sebelum dikosongkan pada proses komputasi
    printf("Stack input: ");
    printStack(&stacknya);

    int j;
    // Dummy node
    // Node *n1 = NULL;
    // Node *n2 = NULL;

    int hasilkpk = 0;

    // n1 = stacknya.head;
    // n2 = stacknya.head->next;
    // struct Node *p = stacknya.head;
    int val1, val2;

    while (stacknya.head->next != NULL){
        if (coprime(stacknya.head->data, stacknya.head->next->data)) {
            // tidak terjadi apa apa
            push(&tempStack, pop(&stacknya));
        }

        else {
            val1 = pop(&stacknya);
            val2 = pop(&stacknya);
            hasilkpk = lcm(val1, val2);
            push(&stacknya, hasilkpk);
        }

    }

    push(&tempStack, pop(&stacknya));

    // print hasil algoritma
    printf("\nStack output: ");
    printStack(&tempStack);

    return 0;
}

    // fungsi push elemen ke stack
    // REFERENSI: Tutorial Modul 7
    void push(struct Stack* stack, int new_data) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = new_data;
        new_node->next = stack->head;

        stack->head = new_node;
    }

    // fungsi untuk pop elemen terakhir dari stack
    // REFERENSI: Tutorial Modul 7
int pop(struct Stack* stack) {
    int ret_val = 0;
    struct Node* temp = stack->head;

    if (temp != NULL) {
        ret_val = temp->data;
        stack->head = temp->next;

        free(temp);
    }

    return(ret_val);
}

// fungsi mencari FPB antara bilangan x dan y
int gcd(int x, int y){
    while(x != y) {
        if(x > y)
            x -= y;
        else
            y -= x;
    }

    int ret = x;
    return ret;
}

// fungsi mencari KPK antara bilangan x dan y
int lcm(int x, int y){
    int result = (x*y) / gcd(x, y);

    return result;
}

// fungsi mencari koprima antara bilangan x dan y
// return 1 bila koprima
// return 0 bila bukan koprima
int coprime(int x, int y){
    if (gcd(x,y) == 1){
        return 1;
    }

    else{
        return 0;
    }
}

// fungsi untuk print elemen stack
// Silakan sesuaikan bentuk data anda dengan yang anda gunakan
void printStack(struct Stack *x) {
    struct Node *temp = x->head;

        if (temp == NULL){
            printf("[empty]\n");

            return;
        }
    printf("[");

    while (temp->next != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }

    printf("%d]\n", temp->data);
}
