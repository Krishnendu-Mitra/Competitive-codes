
#include<stdio.h>
#include<stdlib.h>
//code by krish
struct Node{
    int element;
    struct Node* link;
};
typedef struct Node node;
node *head;
node *createNode(int element){
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp -> element = element;  
    temp -> link = NULL;
    return temp;
}
void push(node** head, int new_element){
    node *krish = createNode(new_element);
    krish -> link = (*head);
    (*head) = krish;
    // node *krish = createNode(new_element);
    // node *cache = head;
    // while(cache->link!=NULL){ //this loop shift my index at the last position
    //    	cache=cache->link;
    // }
    // cache->link=krish;
    // krish->link= NULL;
}
void display(node* head){
    node* temp = head;
    printf("<<< ");
    while(temp){
        printf(" %d ",temp->element);
        temp = temp -> link;
    }
    printf("\n");
}
void swap(node *a, node *b){
    int temp = a -> element;
    a -> element = b -> element;
    b -> element = temp;
}
void calculation(node *head){
    int cache = 0;
    node* past = head;
    node* present = head->link;
    if(head == NULL){
        return;
    }
    while(present){
        if(past->element > present->element){
            swap(past, present);
        }else{
            cache++;
        }
        if(present->link && present->link->element > present->element){
            swap(present->link, present);
        }else{
            cache++;
        }
        past = present->link;
        if(!present->link){
            break;
        }else{
            cache++;
        }
        present = present->link->link;
    }
}
void play(){
    int i, temp, n;
    node *head = NULL;
    printf("Enter the size of your list: ");
    scanf("%d",&n);
    printf("Please give the sorted  & revers list\n");
    for(i = 0; i <= n - 1; i++){
        printf("%d no element = ",i+1);
        scanf("%d",&temp);
        push(&head, temp);
    }
    printf("Your given list is: \n");
    display(head);
    calculation(head);
    printf("Result is: \n");
    display(head);
}
int main(){
    play();//only one function call here
    return 0;
}