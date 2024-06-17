INFIX TO POSTFIX

#include <stdio.h>
#include <string.h>
#define size 20
int stack[size], top = -1;
char expr[size], post[size];

void Push(char s);
char Pop();
char Top();
int Priority(char s);

int main(){
    int i;
    printf("Enter the infix expression : ");
    fgets(expr,size,stdin);
    for(i = 0; i < strlen(expr); i++){
        if(expr[i] >= 'a' && expr[i] <= 'z')
            printf("%c", expr[i]);
        else if(expr[i] == '(')
            Push(expr[i]);
        else if(expr[i] == ')'){
            while(Top() != '(')
                printf("%c", Pop());
            Pop();
        }
        else{
            while(Priority(expr[i])<=Priority(Top()) && top!=-1)
                printf("%c", Pop());
            Push(expr[i]);
        }
    }
    for(i = top; i >= 0; i--)
        printf("%c", Pop());
    return 0;
}

void Push(char s){
    top = top + 1;
    stack[top] = s;
}
char Pop(){
    char e;
    e = stack[top];
    top = top - 1;
    return e;
}
char Top(){
    return stack[top];
}
int Priority(char s){
    int p = 0;
    switch(s){
        case '(':
        p = 0;
        break;
        
        case '+':
        case '-':
        p = 1;
        break;
        
        case '*':
        case '/':
        case '%':
        p = 2;
        break;
        
        case '^':
        p = 3;
        break;
    }
    return p;
}
