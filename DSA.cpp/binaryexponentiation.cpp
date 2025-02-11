#include <iostream>
using namespace std;

int main(){
    int num , pow;
    cout <<"Enter Number : ";
    cin >> num;
    cout << "Enter Power : ";
    cin >> pow;
    cout << "Input : " << num <<"^" <<pow;
    long binForm = pow;
    double ans = 1;
    if(pow < 0){
        x = 1 / x;
        binForm = -binForm;
    }
    while(binForm > 0){
        if(binForm % 2 == 1){
            ans *= num;
        }
        num *= num;
        binForm /= 2;
    }
    cout << "\nOutput ---> "<< ans;
    return 0;
}