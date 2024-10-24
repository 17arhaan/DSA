#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        arr[top] = item;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        int item = arr[top];
        top--;
        printf("%d popped\n", item);
    }
}

void peak() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        int item = arr[top];
        printf("%d is at the top of the stack.\n", item);
    }
}

void Display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements-------> ");
        for (int i = 0; i <= top; i++) {
            printf(" |%d| ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int input, element;
    printf("\n------ MENU ------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    do {

        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                printf("%d element pushed. \n",element);
                push(element);
                break;

            case 2:
                pop();
                break;

            case 3:
                peak();
                break;

            case 4:
                Display();
                break;

            case 5:
                printf("! Exit !\n");
                break;

            default:
                printf("Invalid Option\n");
        }
    } while (input != 5);
    return 0;
}
