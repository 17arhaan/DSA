#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int x){
    if ( rear == MAX_SIZE - 1){
        printf("Overflow");
    } else if (front == -1 && rear == -1){
        front = rear == 0;
        queue[rear] = x;
    } else {
        rear ++;
        queue[rear] = x;                        
    }
}
void dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow");
    } else if(front == rear){
        front = rear == -1;
    } else {
        printf("%d dequeued",queue[front]);
        front++;
    }
}
void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty.");
    } else {
        printf("Queue elements-------> ");
        for (int i = front; i < rear + 1; i++) {
            printf(" |%d| ", queue[i]);
        }
    }
}

int main() {
    int input, element;

    do {
        printf("\n------ MENU ------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("Enter element : ");
                scanf("%d", &element);
                printf("%d enqueued. ",element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("! Exit !\n");
                break;

            default:
                printf("Invalid Option\n");
        }
    } while (input != 4);
    return 0;
}
