#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Length : ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }

    cout << "\nArray --->\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Unique Value(s) : \n";
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
