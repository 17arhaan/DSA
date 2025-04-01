#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> arr,int tar){
    int st = 0 , end = arr.size()-1;
    while (st <= end){
        int mid = (st + end) / 2;
        if(tar > arr[mid]){
            st = mid + 1;
        } else if(tar < arr[mid]){
            end = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
int main(){
    int tar1 = 9 , tar2 = 0;
    vector <int> arr1 = {-1,0,3,4,5,9,12}; //!odd
    cout << "Target 1 idx : "<<binarySearch(arr1,tar1) << endl;
    vector <int> arr2 = {-1,0,1,3,4,5,9,12}; //?even
    cout << "Target 2 idx : "<<binarySearch(arr2,tar2) << endl;
    return 0;
}