#include <stdio.h>
#include  <stdlib.h>

struct Node{
    struct Node*next;
    int data;
};

struct Node* top = NULL;

void push(int value){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if(!newnode){
        printf("newnode is NULL \n");
        exit(1);
    }
    newnode->data=value;
    newnode->next=top;
    top=newnode;
    printf("%d is pushed into the stack \n",value);
}

int pop(){
    if(top==NULL){
        printf("stack is empty \n");
        exit(1);
    }
    int value = top->data;
    struct Node* temp = top;
    top = top-> next;
    free(temp);
    return value;
}

void Display(){
    struct Node* temp = top;
    if(top == NULL){
        printf("stack is empty \n");
        exit(1);
    }
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    Display();
    pop();
    Display();
    pop();
    Display();
    pop();
    Display();
    pop();
    Display();

    return 0;
}
