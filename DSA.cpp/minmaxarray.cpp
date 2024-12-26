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
    cout << "Input Array --->";
    cout << endl;
    for (int i = 0 ; i < n ; i++ ){
        cout << arr[i] << " ";
    }
    int min = INT8_MAX; // arr[0]
    int max = 0; // arr[0]
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout << endl;
    cout << "Largest : " << max << " | " <<"Smallest : " << min;
    return 0;
}