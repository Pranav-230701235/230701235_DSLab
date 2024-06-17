#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* head = NULL;

void isempty() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List is not empty.\n");
    }
}

void insertatfirst() {
    struct node* newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!");
        return;
    }
    int data;
    printf("Enter element you want to insert: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertlast() {
    struct node* newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!");
        return;
    }
    int data;
    printf("Enter element you want to insert: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void display() {
    struct node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int Islast(){

    struct node* pos;
    pos=head;
if(pos->next == NULL)
return 1;
else
return 0;
}
void findprevious() {
    int key;
    printf("enter key");
    scanf("%d",&key);
    struct node *position = head;
    struct node *prev = NULL;
    while (position != NULL && position->data != key) {
        prev = position;
        position = position->next;
    }
    if (position != NULL && prev != NULL) {
        printf("Previous element of %d is %d\n", key, prev->data);
    } else {
        printf("Previous element not found.\n");
    }
}
void *find(){

struct node* position;
int x;
int current=1;
printf("enter the element");
scanf("%d",&x);
position = head->next;
while(position != NULL && position->data != x){
position = position->next;
current++;
}
printf("element is foundbin position %d",current);
return 0;
}
void *findnext(){
struct node* findnext=head->next;
int x;
printf("enter element you want to find");
scanf("%d",&x);
int current=1;
while(findnext->data!=x){
    findnext=findnext->next;
    current++;
}
printf("next element %d is found at position %d",findnext->next->data,current+1);
return 0;
}


void insertafter() {
    
    struct node* newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    int data;
    printf("Enter element you want to insert: ");
    scanf("%d", &data);
    newnode->data = data;
    int position;
    printf("Enter the position: ");
    scanf("%d", &position);
    struct node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    struct node* p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void deletefirst(){
    struct node *temp;
    temp=head->next;
    head->next=temp->next;
    free(temp);
    struct node *p;
    p=head->next;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }

}
void deleteafterp() {
  int position;
  printf("enter position ");
  scanf("%d",&position);
    struct node *temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position is invalid.\n");
    } else {
        struct node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

void deletelast(){
    struct node *p;
    p=head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    p->next=NULL;
    free(p->next);
    struct node *temp=head->next;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void deletelist() {
    struct node *temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
}



int main() {
    int n;
    do {
        printf("Enter the operation you want to perform:\n1. Insert at beginning\n2. Insert at end\n3. Display\n4. Isposlast\n5. find previous\n6. Findnext\n7. Find\n8. isempty\n9. insertafter\n 10.deletefirst\n 11.delete after p\n 12.Deletelast\n 13.Deletelist\n 0.exit");
        scanf("%d", &n);
        switch (n) {
            case 1:
                insertatfirst();
                break;
            case 2:
                insertlast();
                break;
            case 3:
                display();
                break;
            case 4:
                if(Islast()){
                    printf("it is last");
                }
                else{
                    printf("it is not");
                }
            case 5:
               findprevious();
               break;
             case 6:
              findnext();
              break;
              case 7:
              find();
              break;
              case 8:
              isempty();
              break;
              case 9:
              insertafter();
              break;
              case 10:
              deletefirst();
              break;
              case 11:
              deleteafterp();
              break;
              case 12:
              deletelist();
              break;
              case 0:
              exit(0);
              break;
        }
    } while (n!=0);
}
