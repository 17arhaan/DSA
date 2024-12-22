#include <iostream>
using namespace std;

int digitSum (int number){
    int sum = 0;
    int digit = 0;
    while (number > 0){
        digit = number % 10 ;
        number = number / 10;
        sum += digit;
    }
    return sum;
}
int main(){
    int n;
    cout << "Enter Number : ";
    cin >> n;
    int sum = digitSum(n);
    cout << " Sum : " << sum;
    return 0;
}