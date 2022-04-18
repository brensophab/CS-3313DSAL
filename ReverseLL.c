//Question 4//
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
//function to iteratively reverse the ll

static void reverse(struct Node ** head_ref){
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while(current != NULL){
        next = current->next; // store next
        current->next = prev; // rev current ptr

        prev = current; // move ptr up by 1 position
        current = next;
    }
    *head_ref = prev;
}

//fn to push node onto ll//
void push(struct Node ** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//printlist function //
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp !=NULL){
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 9);
    push(&head, 4);
    push(&head, 7);
    push(&head, 2);
    push(&head, 15);
    push(&head, 23);
    push(&head, 26);
    push(&head, 11);
    push(&head, 8);

    printf("Current linked list is\n");
    printList(head);
    reverse(&head);
    printf("\n Reversed linked list is\n");
    printList(head);

    return 0;
}