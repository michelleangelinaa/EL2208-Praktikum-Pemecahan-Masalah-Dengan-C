/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
 *  Modul               : 7 - Stacks and Queues
 *  Percobaan           : Tutorial
 *  Hari dan Tanggal    : Jumat, 2 April 2021
 *  Nama File           : tutorial-07-stack.c
 *	Pembuat				: Tito Irfan
 *  Deskripsi           : Source code tutorial untuk modul 07, materi stack.
 */

/** Perintah Kompilasi
 * 
 * Linux/MacOS  - gcc -o tutorial-07-stack tutorial-07-stack.c stack_lib.c
 * Windows      - gcc -o tutorial-07-stack.exe tutorial-07-stack.c stack_lib.c
 * 
 * atau dengan Makefile:
 * 
 * Linux/MacOS - make stack
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack_lib.h"

int main() {
    
    // Catatan:
    //  pop tidak harus return 0 ketika stack
    //  kosong. Pada contoh ini dibuat demikian 
    //  agar lebih mudah dipahami.
    //  anda bisa mengganti 0 dengan INT_MIN misalnya.

    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->head = NULL;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Current stack content:\n");
    printStack(stack);

    printf("\nPop, got: %d\n", pop(stack));
    printf("Front of stack: %d\n", peek(stack));
    printf("Current stack content:\n");
    printStack(stack);

    printf("\nPop, got: %d\n", pop(stack));
    printf("Front of stack: %d\n", peek(stack));
    printf("Current stack content:\n");
    printStack(stack);

    printf("\nPop, got: %d\n", pop(stack));
    printf("Front of stack: %d\n", peek(stack));
    printf("Current stack content:\n");
    printStack(stack);

    free(stack);
    
    return 0;
}