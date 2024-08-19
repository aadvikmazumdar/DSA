#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}Node;
struct Node* createNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(Node));
    newnode ->data = data;
    newnode ->next = NULL;
    return newnode;
}
void Insertbegin(struct Node** head,int data){
    struct Node* newnode =createNode(data);
    newnode->next=*head;
    *head=newnode;
    printf("\n");
    return; 
}
void Insertend(struct Node** head,int data){
    struct Node* newnode = createNode(data);
    newnode->next=NULL;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp =temp->next;
    }
    temp->next=newnode;
    printf("\n");
}

void deletenode(struct Node** head,int key){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if((temp!=NULL && temp->data == key)){
        *head = temp->next;
        return;
    }
    while(temp!=NULL && temp->data != key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}
void display(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;

    Insertend(&head,5);
    Insertend(&head,6);
    Insertend(&head,7);
    Insertbegin(&head,4);
    Insertbegin(&head,3);

    display(head);
    deletenode(&head,7);
    display(head);
    return 0;
}