#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return (n * factorial(n - 1));
    }
}

int main() {
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    int result = factorial(num);
    if (num < 0) {
        printf("Invalid Input\n");
    } else {                         
        printf("The factorial of %d is: %d\n", num, result);
    }

    return 0;
}
