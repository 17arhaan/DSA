#include<iostream>
using namespace std;
int main(){
    int n,target;
    cout << "Enter Length : ";
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i++ ){
        cout << "Enter Element [" << i+1 <<"] : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Array --->";
    cout << endl;
    for (int i = 0 ; i < n ; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter Target : ";
    cin >> target;
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] == target) cout << "Target Found !! at Index ---> " << i+1;
    }
    return 0;
}