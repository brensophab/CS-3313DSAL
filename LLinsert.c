//Question 1
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
//node struct
typedef struct node{
    int data;
    struct node *next;
} Node;
Node* insertNewNode(int, Node*);
//function declares
    Node *insertAfter(int, int, Node*);
    void print(Node*);
    int count(Node*);


//Function to insert after an element in a list// 
Node *insertAfter(int num, int prev_num, Node *head){
    Node *current_node = head;
    Node *new_node;
    while(current_node->data != prev_num){
        current_node = current_node->next;

    }
    new_node =(Node*)malloc(sizeof(Node));
    new_node->data = num;
    new_node->next = current_node->next;
    current_node->next= new_node;
    return head;
}

//Function to print all elements in a linked list
void print(Node *head){
    Node *current_node = head;
    while(current_node != NULL){
        printf("%d", current_node->data);
        current_node=current_node->next;
    }
}

int main(){
    
    Node *head;
    int num, prev_num, next_num;
    char *temp;
    char ch;

    printf("Enter a number to insert:\n");
    
    if(scanf("%d", &num) != 1) {
        printf("Invalid input, please try again. \n");
        scanf("%s", &temp);
    }
    printf("After which number do you want to insert?\n");
    if(scanf("%d", &prev_num) != 1){
        printf("Error, invalid input.\n");
        scanf("%s", &temp);
    }
   
        head = insertAfter(num, prev_num, head);
        printf("%d is inserted after %d", num, prev_num);
    
    
    printf("\nPress a key to continue.\n");
    
    return 0;



}
