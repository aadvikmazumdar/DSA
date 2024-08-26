#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}Node;

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertBegin(struct Node** head,int data){
    struct Node* newNode = CreateNode(data);
    newNode->next=*head;
    *head=newNode;
    return;
}

void InsertPosition(struct Node** head,int position,int data){
    struct Node* newNode = CreateNode(data);
    struct Node* temp = *head;
    int count = 0;
    while(temp != NULL && count < position - 1){
        temp = temp->next;
        count++;
    }
    if(position == 0){
        newNode->next=*head;
        *head = newNode;
        return;
    }
    if(temp==NULL){
        free(temp);
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void InsertEnd(struct Node** head, int data){
    struct Node* newNode = CreateNode(data);
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    if(head==NULL){
        *head=newNode;
        return;
    }
    temp->next=newNode;
}

void Deletion(struct Node** head,int key){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while(temp!=NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data != key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void Display(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;

    InsertBegin(&head,2);
    InsertBegin(&head,1);
    InsertEnd(&head,5);
    InsertEnd(&head,6);
    InsertPosition(&head,2,3);
    InsertPosition(&head,3,4);
    Display(head);
    Deletion(&head,4);
    Display(head);

    return 0;
}