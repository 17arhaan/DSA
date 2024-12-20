#include <iostream>
using namespace std;
int main(){
    int num , sum = 0;
    cout << "Enter N : ";
    cin >> num;
    for (int i = 0 ; i < num ; i ++){
        if(i % 3 == 0){
            sum += i;
        }
    }
    cout << "Sum : " << sum << endl;
    return 0;
}
