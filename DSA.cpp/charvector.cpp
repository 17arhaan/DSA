#include<iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout << "Enter Length : ";
    cin >> n;
    vector<char > vec(n);
    cout << endl;
    for (int i = 0 ; i < n ; i++ ){
        cout << "Enter Element [" << i+1 <<"] : ";
        cin >> vec[i];
    }
    cout << "Vector --->";
    cout << endl;
    for (char i : vec ){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}