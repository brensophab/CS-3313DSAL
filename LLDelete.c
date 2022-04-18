//Question 2

#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node * next;
}*head = NULL, *tail = NULL;

void push(int);
void displayList();
void delete(int);

void delete(int pos){
    struct node *temp = head;
    int i;
    if(pos==0){
        printf("\nElement deleted is: %d\n", temp->data);
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else{
        for(i=0;i<pos - 1;i++){
            temp = temp->next;
        }

        struct node *del = temp->next;
        temp->next = temp->next->next;
        printf("\nElement deleted is %d\n", del->data);
        del->next = NULL;
        free(del);
    }
    
    printf("\nUpdated LL is :\n");
    displayList();
    return;
}

void push(int value){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(head==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
    return;
}

void displayList(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        if(temp->next==NULL){
            printf("%d->NULL", temp->data);
        }
        else{
            printf("%d->\n", temp->data);
        }
        temp=temp->next;
    }
    return;
}

int main(){
   
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    push(11);
    push(12);
    push(13);
    push(14);
    push(15);
    push(16);
    push(17);
    push(18);
    push(19);
    push(20);
    printf("Linked list is ");
    displayList();
    
    
    delete(2);
    
    printf("Final LL is \n");
    displayList();
    return 0;
}
