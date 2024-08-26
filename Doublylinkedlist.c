#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

struct Node* createnode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void insertbegin(struct Node** head,int data){
    struct Node* newnode = createnode(data);
    if(*head == NULL){
        *head = newnode;
    }
    else{
        newnode->next=*head; // newnode's next value is the current head value 
        (*head)->prev=newnode;// current head's previous value is newnode 
        *head=newnode;// newnode becoming the new head value
    }
}

void insertend(struct Node** head, int data){
    struct Node* newnode = createnode(data);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void insertposition(struct Node** head, int position,int data){
    struct Node* newnode= createnode(data);
    if(position==0){
        newnode->next=*head;
        *head=newnode;
        if(*head!=NULL){
            (*head)->prev=newnode;
        }
    }
    struct Node* temp = *head;
    int count=0;
    while(temp!=*head && count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=newnode;// temp ke next ka previous = newnode This makes the node after temp point back to newNode as its previous node.

    }//This ensures that the backward link from the node after newNode is correctly updated

    temp->next=newnode;
    newnode->prev=temp;
}

void deletion(struct Node** head,int data){
    struct Node* temp = *head;
    while(temp!=NULL && temp->data != data){
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next; // makes temp's previous node = temp's next node aka deleting the temp node
    }
    else{
        *head=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    free(temp);

}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

    if(head!=NULL){
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
    }
}

int main(){
    struct Node*head = NULL;
    insertbegin(&head, 3);
    insertbegin(&head, 2);
    insertend(&head, 4);
    display(head);
    insertposition(&head, 2, 5);
    display(head);
    deletion(&head,5);
    display(head);

    return 0;
}


