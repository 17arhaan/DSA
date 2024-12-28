#include<iostream>
using namespace std;
int main(){
    int n;
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
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }
    cout << endl;
    cout << "Sum : " << sum;
    int prod = 1;
    for(int i = 0 ; i < n ; i++){
        prod *= arr[i];
    }
    cout << endl;
    cout << "Product : " << prod;
    cout << endl;
    return 0;
}