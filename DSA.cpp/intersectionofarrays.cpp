#include<iostream>
using namespace std;

int intersectionArray(int arr1[] , int arr2[] , int size){
    int intersection;
    for(int i = 0 ; i < size ; i ++){
        for(int j = 0 ; j < size ; j ++){
            if(arr1[i] == arr2[j]) intersection = arr2[j];
        }
    }
    return intersection;
}

void printArray(int arr[], int n){
    for (int i = 0 ; i < n ; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter Length of Arrays : ";
    cin >> n;
    cout << endl;
    int arr1[n];
    int arr2[n];
    for (int i = 0 ; i < n ; i++ ){
        cout << "Enter Element A1 ~ [" << i+1 <<"] : ";
        cin >> arr1[i];
    }
    cout << endl;
    for (int i = 0 ; i < n ; i++ ){
        cout << "Enter Element A2 ~ [" << i+1 <<"] : ";
        cin >> arr2[i];
    }
    cout << endl;
    cout << "Arrays  --->";
    cout << endl;
    printArray(arr1,n);
    printArray(arr2,n);
    int itsc = intersectionArray(arr1,arr2,n);
    cout << " Intersection : " << itsc;
    return 0;
}