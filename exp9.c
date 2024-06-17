#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node *leftChild, *rightChild;
};
struct node *root = NULL;
struct node *newNode(int item) {
 struct node *temp = (struct node *)malloc(sizeof(struct node));
 if (!temp) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 temp->data = item;
 temp->leftChild = temp->rightChild = NULL;
 return temp;
}
void insert(int data) {
 struct node *tempNode = newNode(data);
 struct node *current;
 struct node *parent;
 if (root == NULL) {
 root = tempNode;
 return;
 }
 current = root;
 parent = NULL;
 while (1) {
 parent = current;
 if (data < parent->data) {
 current = current->leftChild;
 if (current == NULL) {
 parent->leftChild = tempNode;
 return;
 }
 } 
 else {
 current = current->rightChild;
 if (current == NULL) {
 parent->rightChild = tempNode;
 return;
 }
 }
 }
}
struct node* search(int data) {
 struct node *current = root;
 while (current != NULL && current->data != data) {
 if (data < current->data) {
 current = current->leftChild;
 } else {
 current = current->rightChild;
 }
 }
 return current;
}
void printTree(struct node* Node) {
 if (Node == NULL) return;
 printTree(Node->leftChild);
 printf(" %d", Node->data);
 printTree(Node->rightChild);
}
struct node* findMin(struct node* node) {
 struct node* current = node;
 while (current && current->leftChild != NULL)
 current = current->leftChild;
 return current;
}
struct node* deleteNode(struct node* root, int data) {
 if (root == NULL) return root;
 if (data < root->data)
 root->leftChild = deleteNode(root->leftChild, data);
 else if (data > root->data)
 root->rightChild = deleteNode(root->rightChild, data);
 else {
 if (root->leftChild == NULL) {
 struct node *temp = root->rightChild;
 free(root);
 return temp;
 } else if (root->rightChild == NULL) {
 struct node *temp = root->leftChild;
 free(root);
 return temp;
 }
 struct node* temp = findMin(root->rightChild);
 root->data = temp->data;
 root->rightChild = deleteNode(root->rightChild, temp->data);
 }
 return root;
}
int main() {
 int choice, data;
 while (1) {
 printf("\nMenu:\n");
 printf("1. Insert\n");
 printf("2. Search\n");
 printf("3. Delete\n");
 printf("4. Print In-order\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter data to insert: ");
 scanf("%d", &data);
 insert(data);
 printf("Insertion done\n");
 break;
 case 2:
 printf("Enter data to search: ");
 scanf("%d", &data);
 struct node *k;
 k = search(data);
 if (k != NULL)
 printf("Element %d found\n", k->data);
 else
 printf("Element not found\n");
 break;
 case 3:
 printf("Enter data to delete: ");
 scanf("%d", &data);
 root = deleteNode(root, data);
 printf("Deletion done\n");
 break;
 case 4:
 printf("BST in-order:\n");
 printTree(root);
 printf("\n");
 break;
 
 case 5:
 exit(0);
 default:
 printf("Invalid choice\n");
 }
 }
 return 0;
}
