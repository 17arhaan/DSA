#include<iostream>
#include<vector>
#define max 99
using namespace std;
int main(){
    int arr[max],n;
    cout<<"Enter Length : ";
    cin>>n;
    cout<<"Enter Elements :-\n";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    for(int st = 0 ; st < n ; st++){
        for(int en = st ; en < n ; en++){
            cout<<arr[en];
        }
        cout<<endl;
    }
}