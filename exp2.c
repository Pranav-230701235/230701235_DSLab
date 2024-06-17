#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
    
};
struct node *head,*tail;


void create(){
    while(1){
    int data;
    int n;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter element you want to insert");
    scanf("%d",&data);
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    printf("do you want to continue enter 1. else 0.");
    scanf("%d",&n);
    if(n==0)
        break;
    
    }
}
void display(){
    
        struct node *temp;
        temp=head;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n ");
    }
    void insertbeg(){
        struct node *newnode;
        int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter element you want to insert");
    scanf("%d",&data);
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        printf("\nlist is empty");
        head=newnode;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
        
    }
void insertend(){
 struct node *newnode;
 int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter element you want to insert");
    scanf("%d",&data);
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        printf("\nlist is empty");
        head=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    }

void deletebeg(){
    struct node *temp;
    if(head==NULL){
        printf("list is empty");
    }
    else{
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
}
void deleteend(){
    struct node *temp;
    if(tail==NULL){
        printf("list is empty");
    }
    else{
        temp=tail;
        tail->prev->next=0;
        tail=tail->prev;
        free(temp);
    }
}
void insertmid(){
    struct node *position;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter element you want to insert");
    scanf("%d",&x);
    newnode->data=x;
    int p;
    printf("Enter the element ");
    scanf("%d",&p);
    
    position=head;
    while(position!=NULL&& position->data!=p){
        position=position->next;
    }
    newnode->next=position->next;
    position->next->prev=newnode;
    position->next=newnode;
    newnode->prev=position;
    
}
void deleteafter(){
    int x;
    printf("Enter position: ");
    scanf("%d", &x);
    struct node *position = head;
    while(position != NULL && position->data != x){
        position = position->next;
    }
    if(position != NULL && position->next != NULL){
        struct node *nodeToDelete = position->next;
        position->next = nodeToDelete->next;
        
        if(nodeToDelete->next != NULL){
            nodeToDelete->next->prev = position;
        }
        
        free(nodeToDelete);
    } else {
        printf("Position not found or already at the end.\n");
    }
}
        
        int main(){
            int choice;
            while(1){
printf("\nenter the operation 1.create\n2.display\n3.insert at beg\n4.insert at end\n5.delete at beg\n6.delete at end\n7.insert mid \n8.deleteafter\n0.Exit");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                create();
                break;
                case 2:
                display();
                break;
                case 3:
                insertbeg();
                break;
                case 4:
                insertend();
                break;
                case 5:
                deletebeg();
                break;
                case 6:
                deleteend();
                break;
                case 7:
                insertmid();
                break;
                case 8:
                deleteafter();
                break;
                case 0:
                exit(0);
                break;
                
            }
            }
        }
