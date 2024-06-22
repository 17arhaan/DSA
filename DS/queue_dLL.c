#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head, *temp, *t;
void Enqueue(int a){
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = a;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        head->prev = NULL;
    }
    else{
        t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
        temp->prev = t;
    }
}
int Dequeue(){
    int a;
    temp = head;
    head = head->next;
    head->prev = NULL;
    a = temp->data;
    free(temp);
    return a;
}
void Display(){
    t = head;
    while(t != NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}
int main(){
    int ch;
    do{
        printf("\nMenu\n1.Enqueue()\n2.Dequeue()\n3.Display()\n4.Exit()\n");
        printf("Input Choice : ");
        scanf("%d",&ch);
        if(ch == 1){
            int ele;
            printf("Element to Add :");
            scanf("%d",&ele);
            Enqueue(ele);
        }
        else if(ch == 2){
            int ele = Dequeue();
            printf("%d Exits the Queue\n",ele);
        }
        else if(ch == 3){
            Display();
        }
        else if(ch == 4){
            printf("!!!Exit!!!\n");
        }
        else{
            printf("Retry\n");
        }
    }while(ch != 4);
    return 0;
}