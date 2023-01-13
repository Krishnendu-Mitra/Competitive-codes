//Question------------------------>
/*Write a menu driven C program for Insertion sort,
Bubble sort, Selection sort with Linear Search and 
Binary search for a simple user define array*/
//Answer-------------------------->
#include<stdio.h>
#include<stdlib.h>
//code by krish
void display(int arr[], int n){
    int i;
    printf("[");//for better style
    for(i=0; i<n-1; i++){
        printf(" %d,",arr[i]);
    }
    printf(" %d]\n",arr[n-1]);//for better style
}
void insertionSort(int arr[], int n){
    int i,j,k=0;
    for(i=0; i<n; i++){
        k = arr[i];
        j = i - 1;
        while(k < arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j+1] = k;
    }
    display(arr,n);//after sort display the sorted list
}
void bubbleSort(int arr[], int n){
    int i,j,temp=0;
    for(j=0; j<n-1; j++){
        for(i=0; i<n-j-1; i++){
            if(arr[i+1] < arr[i]){
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    display(arr,n);
}
void selectionSort(int arr[], int n){
    int i,j,mid=0,temp=1;
    for(i=0; i<n-1; i++){
        mid = i;
        for(j=i+1; j<n; j++){
            if(arr[mid] > arr[j])
                mid = j;
        }//with out using swap function
        temp = arr[mid];
        arr[mid] = arr[i];
        arr[i] = temp;
    }
    display(arr,n);
}
void linearSearch(int arr[], int n, int x){
    int i,loc=-1;
    for(i=0; i<n; i++){
        if(arr[i] == x){
            loc = i + 1;
            i = n*2;//for break the loop easily
        }
    }
    if(loc != -1){
        printf(" %d found in %d no index",x,loc);
    }else{
        printf(" %d not found in this list",x);
    }
    printf("\n");
}
void binarySearch(int arr[], int l, int r, int x){
    int mid = (l+r)/2;
    while(l<=r){
        if(arr[mid]<x){
            l = mid+1;
        }else if(arr[mid]==x){
            printf(" %d found in %d index",x,mid+1);
            break;
        }else{
            r = mid - 1;
        }
        mid = (l+r)/2;//update our assemstion
    }
    if(l>r){
        printf(" %d not found in this list",x);
    }
    printf("\n");
}
void choiseHolder(int arr[], int n){//store all choice
    int i,x,c=0;
    printf("Enter your choice here: ");
    scanf("%d",&c);
    if(c==1){
        insertionSort(arr,n);
    }else if(c==2){
        bubbleSort(arr,n);
    }else if(c==3){
        selectionSort(arr,n);
    }else if(c==4){//search choices start
        printf("Entert the searching value: ");
        scanf("%d",&x);
        linearSearch(arr,n,x);
    }else if(c==5){
        insertionSort(arr,n);//if the list is not sorted, so sort first and then use binary search
        printf("Entert the searching value: ");
        scanf("%d",&x);
        binarySearch(arr,0,n-1,x);
    }else if(c==6){//if any want user need display
        display(arr,n);
    }else{
        printf("Error! given choice not valid, try again..\n");
        choiseHolder(arr,n);
    }
}
void getdata(){//collect all requre data to user
    int i,n,arr[10],x,c=0,r=0;
    printf("Enter your list size(Max size 10): ");
    scanf("%d",&n);
    if(n>0 && n<=10){//check given size valid or not
        for(i=0; i<n; i++){
            printf("%d no value = ",i+1);
            scanf("%d",&arr[i]);
        }
        printf("Your list is: \n");
        display(arr,n);
        do{//loop control variable r is 0
            choiseHolder(arr,n);
            printf("Return controle(0): ");
            scanf("%d",&r);
        }while(r == 0);
    }else{
        printf("Given size is not valid!, Try again...\n");
        getdata();
    }
}
int main(){//main print our menu one time
    printf("\tMenu\t\n");
    printf("-------------------------\n");
    printf("1. Insertion sort,\n2. Bubble sort,\n3. Selection sort,\n4. Linear Search,\n5. Binary search,\n6. Display\n");
    printf("-------------------------\n");
    getdata();//main call only one function
    printf("\n<<<exit()\n");
    return 0;
}