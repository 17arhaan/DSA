#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& vec) {
    cout << "Vector ---> ";
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter Length: ";
    cin >> n;

    vector<int> vec(n);
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter Element [" << i + 1 << "]: ";
        cin >> vec[i];
    }

    printVector(vec);
    return 0;     
}     