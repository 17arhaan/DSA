#include <iostream>
using namespace std;

int factorial(int num){
    int factorial = 1;
    for (int i = 1 ; i <= num ; i ++){
        factorial *= i;
    }
    return factorial;
}

int main() {
    int n;
    cout << "Enter Number : ";
    cin >> n;
    int fact = factorial(n);
    cout << " Factorial : " << fact;
    return 0;
}
