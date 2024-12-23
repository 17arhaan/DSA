#include <iostream>
using namespace std;

void fibonacci(int n) {
    if (n <= 0) {
        cout << "Length must be greater than 0." << endl;
        return;
    }
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    int a = 0, b = 1;
    cout << "0 1 "; 
    for (int i = 2; i < n; i++) {
        int next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the length: ";
    cin >> n;
    cout << "Fibonacci Series up to " << n << " terms: ";
    fibonacci(n);
    return 0;
}
