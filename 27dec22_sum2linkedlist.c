//Question----------------------------------->
/*Given two linked list in this formate, return their
sum. For example, given:
9->9
5->2
You should return 124=(99+25) as:
4->2->1*/
//Answer------------------------------------->
#include<stdio.h>
#include<stdlib.h>
//code by krish(Themes Train)
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
int widthOfTrain(struct Node* node){ //leanth of the total train
    int size = 0;
    while (node != NULL) {
        node = node->link;
        size++;
    }
    return size;
}
node* Boxcar(node* head1, node* head2, int* passenger){
    if (head1 == NULL)
        return NULL;
    int sum;
    node* result = (node*)malloc(sizeof(node));
    result->link = Boxcar(head1->link, head2->link, passenger);
    sum = head1->element + head2->element + *passenger;
    *passenger = sum / 10;
    sum = sum % 10;
    result->element = sum;
    return result;
}
void LHB(node* head1, node* ticketChecker, int* passenger, node** result){
    int sum;
    if (head1 != ticketChecker){
        LHB(head1->link, ticketChecker, passenger, result);
        sum = head1->element + *passenger;
        *passenger = sum / 10;
        sum %= 10;
        loco(result, sum);
    }
}
void adder(node* head1, node* head2, node** result){ //join the train couch
    node* ticketChecker;
    if (head1 == NULL) {
        *result = head2;
        return;
    }else if (head2 == NULL){
        *result = head1;
        return;
    }
    int size1 = widthOfTrain(head1); //leanth of the couch 1
    int size2 = widthOfTrain(head2); //leanth of the couch 2
    int passenger = 0;
    if (size1 == size2){
        *result = Boxcar(head1, head2, &passenger);// same size couch in the train
    }else{
        int diff = abs(size1 - size2);
        if (size1 < size2)
            Swap(&head1, &head2);
        for(ticketChecker = head1; diff--; ticketChecker = ticketChecker->link);
        *result = Boxcar(ticketChecker, head2, &passenger); //when the TT is sleeping
        LHB(head1,ticketChecker, &passenger, result);
    }
    if (passenger)
        loco(result, passenger);//join it
}
void station(){//work area of the train
    struct Node *head1 = NULL, *head2 = NULL, *result = NULL;
    int i, vender, size1, size2;
    printf("Enter the size of your list1: ");
    scanf("%d",&size1);
    printf("Enter the size of your list2: ");
    scanf("%d",&size2);
    printf("Enter list1 elements here: \n");
    for(i = 0; i <= size1 - 1; i++){ //load couch 1
        printf("%d no element = ",i+1);
        scanf("%d",&vender);
        loco(&head1, vender);
    }printf("Enter list1 elements here: \n");
    for (i = 0; i <= size2 - 1; i++){ //load couch 2
        printf("%d no element = ",i+1);
        scanf("%d",&vender);
        loco(&head2, vender);
    }
    printf("Your list1 is: \n");
    display(head1);
    printf("Your list2 is: \n");
    display(head2);
    adder(head1, head2, &result);
    printf("Result is: \n");
    display(result); //Train left the station
    printf("\tThank you\t\n");
}
int main(){
    station(); //only one function call here
    return 0;
}