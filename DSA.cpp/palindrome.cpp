#include <iostream>
using namespace std;

int isPalin (int number){
    int original = number;
    int digit;
    int revNum = 0 ;
    while (number > 0){
        digit = number % 10 ;
        revNum = revNum * 10 + digit;
        number = number / 10;
    }   
    return (revNum == original);
}
int main(){
    int n;
    cout << "Enter Number : ";
    cin >> n;
    if (isPalin(n)) cout << " Palindrome. " << endl;
    else cout << " Not Palindrome." << endl;
    return 0;
}