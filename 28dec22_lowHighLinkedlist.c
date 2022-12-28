//Question------------------------------------->
/*Given a lined list, rearrange the node values such that appear
in alternating 
low -> high -> low -> high -> ...form.
For example, give 1->2->3->4->5..., you should return
1->3->2->5->4...*/
//Answer--------------------------------------->
#include<stdio.h>
#include<stdlib.h>
//code by krish
struct Node{
    int element;
    struct Node* link;
};
typedef struct Node node;
node *head;
node *createNode(int element){//very importent function or this programe
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
void display(node* head,int n){
    node* temp = head;
    printf("<<< ");
    while(temp){
        printf(" %d ",temp->element);
        temp = temp -> link;
    }
    printf("\n");
}
void swap(node *a, node *b){//swap nodes only
    int temp = a -> element;
    a -> element = b -> element;
    b -> element = temp;
}
void calculation(node *head){//main function were the real game done
    int cache = 0;
    node* past = head; //past node
    node* present = head->link; //present node
    if(head == NULL){
        return;
    }
    while(present){
        if(past->element > present->element){
            swap(past, present);
        }else{
            cache++; //importent but not not visible code
        }
        if(present->link && present->link->element > present->element){
            swap(present->link, present);
        }else{
            cache++; //only devloper use
        }
        past = present->link;
        if(!present->link){
            break;
        }else{
            cache++; //check the inner code work
        }
        present = present->link->link;
    }
}
void play(){
    int i, temp, n;
    node *head = NULL;
    printf("Enter the size of your list: ");//leanth of my list
    scanf("%d",&n);
    printf("Please give the sorted  & revers list\n");
    for(i = 0; i <= n - 1; i++){
        printf("%d no element = ",i+1);//get the elements one by one
        scanf("%d",&temp);
        push(&head, temp);
    }//user def list
    printf("Your given list is: \n");
    display(head,n);//throw the head and size
    calculation(head);
    printf("Result is: \n");
    display(head,n);
}
int main(){
    play();//only one function call here
    return 0;
}