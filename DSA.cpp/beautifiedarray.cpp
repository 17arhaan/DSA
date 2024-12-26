#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "==============================" << endl;
    cout << "       ARRAY ANALYZER        " << endl;
    cout << "==============================" << endl;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << endl << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }

    cout << endl << "==============================" << endl;
    cout << "           OUTPUT            " << endl;
    cout << "==============================" << endl;

    cout << "Input Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int max = arr[0];
    int min = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "Largest Element : " << max << endl;
    cout << "Smallest Element: " << min << endl;

    cout << "==============================" << endl;
    cout << "         END OF PROGRAM       " << endl;
    cout << "==============================" << endl;

    return 0;
}
