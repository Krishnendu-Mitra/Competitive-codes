#include<stdio.h>
#include<stdlib.h>
//code by krish
typedef struct Node{
    int data;
    struct Node *link;
}nd;
nd *head;
nd *creatNode(int data){
    nd *temp = (nd*)malloc(sizeof(nd));
    temp -> data = data;
    temp -> link = NULL;
    return temp;
}
void push(){
    int element;
    printf("Enter the value: ");
    scanf("%d",&element);
    nd *temp = creatNode(element);
    if(head == NULL){
        temp -> link = NULL;
    }else{
        temp -> link = head;
    }
    head = temp;
}
void pop(){
    nd *temp = head;
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    int element = head -> data;
    head = head -> link;
    free(temp);
    printf("Deleted value is: %d\n",element);
}
void peek(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Peek value is: %d\n",head->data);
}
void display(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }else{
        nd *temp = head;
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp -> link;
        }
        printf("NULL\n");
    }
}
void choise(int c){
    int n,i,j;
    if(c==1){
        printf("How many value want to insert: ");
        scanf("%d",&j);
        for(i=0; i<j; i++){push();}
    }else if(c==2){
        pop();
    }else if(c==3){
        display();
    }else if(c==5){//hidden choice
        peek();
    }else{
        printf("Error!\n");
    }
}
int main(){
    int i=0,c;
    printf("----------------------------\nPress 1 for Push\nPress 2 for Pop\nPress 3 for Display\nPress 4 for Quit\n----------------------------\n");
    while(i==0){
        printf("Enter your choice: ");
        scanf("%d",&c);
        if(c == 4){
            i =  1;
        }else{
            choise(c);
        }
    }
    return 0;
}