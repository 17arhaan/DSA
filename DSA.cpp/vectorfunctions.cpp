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

    // Functions ----->

    cout << "Size: " << vec.size() << endl;

    vec.push_back(7);
    cout << "Pushed Element." << endl;
    printVector(vec);

    vec.pop_back();
    cout << "Popped Element." << vec.size() ;
    printVector(vec);

    cout << "Front Element: " << vec.front() << endl;
    cout << "Back Element: " << vec.back() << endl;

    if (vec.size() > 2) {
        cout << "Value at index 2: " << vec.at(2) << endl;
    } else {
        cout << "Index is out of bounds." << endl;
    }

    printVector(vec);

    return 0;
}
