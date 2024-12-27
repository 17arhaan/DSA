#include <iostream>
#define max 99
using namespace std;

void reverseArray(int arr[max],int n){
    int start = 0;
    int end = n - 1;
    while (start < end){
        swap(arr[start],arr[end]);
        start ++;
        end --;
    }
}
int main() {
    int n;
    cout << "Enter Length : ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }

    cout << endl << "Array --->" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    // for (int i = 0, j = n - 1; i < j; i++, j--) {
    //     swap(arr[i], arr[j]);
    // }


    // for (int i = 0; i < n / 2; i++) {
    //     for (int j = n - i - 1; j > i; j--) {
    //         swap(arr[i], arr[j]);
    //         break; // Break after one swap to simulate nested loop behavior
    //     }
    // }
    reverseArray(arr,n);
    cout << "Reversed Array --->" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
