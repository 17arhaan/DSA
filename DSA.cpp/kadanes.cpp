#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[max],n;
    cout<<"Enter Length : ";
    cin>>n;
    cout<<"Enter Elements :-\n";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int maxSum = INT_MIN; 
    int currSum =0; 
    for(int val : arr){
        currSum += val;
        maxSum = max(currSum , maxSum);
        if (currSum < 0) currSum = 0;
    }    
    return maxSum;
}
