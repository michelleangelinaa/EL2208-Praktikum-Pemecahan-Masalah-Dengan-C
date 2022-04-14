#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node* next;
}Node;

typedef struct Stack {
    Node* head;
} Stack;

/*
* fungsi untuk mengurutkan isi stack
*
* @param head: pointer to pointer to head of the stack
*/
void sortStack(Node **head) {

}

void printStack(Stack* stack) {
    Node* current = stack->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void push(Stack* stack, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = stack->head;

    stack->head = new_node;
}

int main()
{
    Node* head = NULL;
    push(&head,5);
    push(&head,4);
    push(&head,8);
    push(&head,3);
    push(&head,7);
    push(&head,1);

    print(head);
    sortStack(head);

    print(head);
    free(head);

    return 0;
}
