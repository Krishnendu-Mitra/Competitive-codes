#include<stdio.h>
#include<stdlib.h>
//code by krish(Themes Train)
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
void loco(struct Node** head, int new_element){ 
    node *krish = createNode(new_element);
    krish->link=(*head);
    (*head)=krish;      
}
void display(struct Node* node){
    printf("<<< ");
    while (node != NULL){
        printf(" %d ", node->element);
        node = node->link;
    }
    printf("\n");
}
void Swap(node** a, node** b){
    node* t = *a;
    *a = *b;
    *b = t;
}
int widthOfTrain(struct Node* node){
    int size = 0;
    while (node != NULL) {
        node = node->link;
        size++;
    }
    return size;
}
node* Boxcar(node* head1, node* head2, int* carry){
    if (head1 == NULL)
        return NULL;
    int sum;
    node* result = (node*)malloc(sizeof(node));
    result->link = Boxcar(head1->link, head2->link, carry);
    sum = head1->element + head2->element + *carry;
    *carry = sum / 10;
    sum = sum % 10;
    result->element = sum;
    return result;
}
void LHB(node* head1, node* cur, int* carry, node** result){
    int sum;
    if (head1 != cur){
        LHB(head1->link, cur, carry, result);
        sum = head1->element + *carry;
        *carry = sum / 10;
        sum %= 10;
        loco(result, sum);
    }
}
void adder(node* head1, node* head2, node** result){
    node* cur;
    if (head1 == NULL) {
        *result = head2;
        return;
    }else if (head2 == NULL){
        *result = head1;
        return;
    }
    int size1 = widthOfTrain(head1);
    int size2 = widthOfTrain(head2);
    int carry = 0;
    if (size1 == size2)
        *result = Boxcar(head1, head2, &carry);
    else {
        int diff = abs(size1 - size2);
        if (size1 < size2)
            Swap(&head1, &head2);
        for(cur = head1; diff--; cur = cur->link);
        *result = Boxcar(cur, head2, &carry);
        LHB(head1,cur, &carry, result);
    }
    if (carry)
        loco(result, carry);
}
void station(){
    struct Node *head1 = NULL, *head2 = NULL, *result = NULL;
    int i, vender, size1, size2;
    printf("Enter the size of your list1: ");
    scanf("%d",&size1);
    printf("Enter the size of your list2: ");
    scanf("%d",&size2);
    printf("Enter list1 elements here: \n");
    for(i = 0; i <= size1 - 1; i++){
        printf("%d no element = ",i+1);
        scanf("%d",&vender);
        loco(&head1, vender);
    }printf("Enter list1 elements here: \n");
    for (i = 0; i <= size2 - 1; i++){
        printf("%d no element = ",i+1);
        scanf("%d",&vender);
        loco(&head2, vender);
    }
    adder(head1, head2, &result);
    display(result);
}
int main(){
    station();
    return 0;
}