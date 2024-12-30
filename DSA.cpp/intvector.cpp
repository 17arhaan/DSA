#include<iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout << "Enter Length : ";
    cin >> n;
    vector<int> vec(n , 0);
    cout << endl;
    cout << "Vector --->";
    cout << endl;
    for (int i : vec ){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}