#include <iostream>
using namespace std;

int main() {
    int l;
    cout << "Enter Length: ";
    cin >> l;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (i == 0 || i == l - 1 || j == 0 || j == l - 1 || i == j || i + j == l - 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;  // New line after each row
    }
    return 0;
}
