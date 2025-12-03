#include<stdio.h>
#include<string.h>

typedef struct Bookshelf{
    int bookID;
    int popularity;
}Bookshelf;

void addBook(Bookshelf* p, Bookshelf* n, int capacity){
    printf("Enter the book ID:");
    scanf("%d", &((*n).bookID));
    printf("Enter popularity:");
    scanf("%d", &((*n).popularity));
    
    for(int i = 0; i < capacity; i++){
        if((*n).bookID == (*(p + i)).bookID){
            (*(p+i)).popularity = (*n).popularity;
            return;
        }
    }
    for(int i = 0; i < capacity; i++){
        if((*(p + i)).popularity>(*n).popularity){
            continue;
        }
        else{
            (*(p + i)).bookID  = (*n).bookID;
            (*(p + i)).popularity  = (*n).popularity;
            return;
        }
    }
    return;
    
}

int accessBook(Bookshelf* p, int n){
    int id;
    printf("Enter the id of the book:");
    scanf("%d", &id);
    for(int i = 0; i < n; i++){
        if((*(p+i)).bookID == id){
            return (*(p + i)).popularity;
        }
    }
    return -1;
}

int main(){

    int capacity, operations;
    printf("Enter the book capacity on the shelf:");
    scanf("%d", &capacity);

    printf("Enter number of operations:");
    scanf("%d", &operations);

    Bookshelf arr[capacity];
    Bookshelf n;

    int j = 0;
    for(int i = 0; i < capacity; i++){
        printf("Enter the book ID:");
        scanf("%d",&(arr[i].bookID));
        printf("Enter popularity:");
        scanf("%d",&(arr[i].popularity));
        j++;
    }

    while(j < operations){
        j++;
        int choice;
        printf("Enter 0 to access book and 1 to add book on the shelf:");
        scanf("%d", &choice);
        switch(choice){
            case 0:{
                int result = accessBook(arr, capacity);
                printf("%d\n", result);
                break;
            }
            case 1:
                addBook(arr, &n, capacity);
                break;
            default:
                printf("Wrong choice!!");
        }
        
    }


    return 0;
}
