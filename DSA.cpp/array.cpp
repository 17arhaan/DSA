#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter Length : ";
    cin >> n;
    int marks[n];
    for (int i = 0 ; i < n ; i++ ){
        cout << "Enter Element [" << i+1 <<"] : ";
        cin >> marks[i];
    }
    cout << endl;
    cout << "Array --->";
    cout << endl;
    for (int i = 0 ; i < n ; i++ ){
        cout << marks[i] << " ";
    }
    cout << endl;
    return 0;
}