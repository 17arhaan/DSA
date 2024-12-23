#include <iostream>
using namespace std;

void primeRange(int n) {
    if (n < 2) {
        cout << "Invalid Response" << endl;
        return;
    }
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the range [2 to ?]: ";
    cin >> n;
    primeRange(n);
    return 0;
}
