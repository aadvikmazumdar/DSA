#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
    int exp;
    struct node* next;
};

struct node* createnode(int coef,int exp){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=coef;
    newnode->exp=exp;
    newnode->next=NULL;
    return newnode;
}

void addTerm(struct node** head,int coef,int exp){
    struct node* newnode = createnode(coef,exp);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node* temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
}

void print(struct node* head){
    while(head!=NULL){
        printf("%dx^%d",head->coef,head->exp);
        head=head->next;
        if(head!=NULL){
            printf(" + ");
        }    
    }
    printf("\n");
}

struct node* addpolynomials(struct node* poly1,struct node* poly2){
    struct node* result = NULL;
    while(poly1 != NULL && poly2 != NULL ){
        if(poly1->exp > poly2->exp){
            addTerm(&result,poly1->coef,poly1->exp);
            poly1=poly1->next;
        }
        else if(poly1->exp < poly2->exp){
            addTerm(&result,poly2->coef,poly2->exp);
            poly2=poly2->next;
        }
        else{
            addTerm(&result,poly1->coef + poly2->coef,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }

    while (poly1!=NULL){
        addTerm(&result,poly1->coef,poly1->exp);
        poly1=poly1->next;
    }
    while(poly2!=NULL){
        addTerm(&result,poly2->coef,poly2->exp);
        poly2=poly2->next;
    }
    return result;
}

int main(){
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* polySum = NULL;

    addTerm(&poly1,3,2);
    addTerm(&poly1,5,1);
    addTerm(&poly1,1,0);

    addTerm(&poly2, 4, 2);
    addTerm(&poly2, 2, 1);
    addTerm(&poly2, 1, 0);

    print(poly1);
    print(poly2);
    polySum=addpolynomials(poly1,poly2);
    print(polySum);

    return 0;
}