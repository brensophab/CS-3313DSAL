//Question 3//
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

//Push an element to the front of the list
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node** head_ref, int key){
    //store head
    struct Node *temp = *head_ref, *prev;

    //if head is to be deleted
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    //Search for node to be deleted, keeps track of prev node
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    
    //if not init present
    if(temp == NULL){return ;}

    //unlink node from LL
    prev->next = temp->next;

    free(temp);
}

void printlist(struct Node* node){
    while(node != NULL){
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(){

    int delete;
    //Empty List// 
    struct Node* head = NULL;
    for(int i = 0; i<20;i++){
        push(&head, i);
        
    }
   

    printlist(head);

    printf("Insert item to delete");
    scanf("%d", delete);
    deleteNode(&head, &delete);
    printf("New ll is: ");
    printlist(head);
}