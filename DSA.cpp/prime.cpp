#include <iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter the number : ";
    cin >> num;
    if (num <= 1){
        cout << "Composite.";
        return 0;
    }
    bool isPrime = true;
    for (int i = 2 ; i <= num / 2 ; i++){
        if(num % i == 0){
            isPrime = false;
            break;
        } else {
            isPrime = t
            rue;
        }
    }
    if (isPrime) cout << "Prime.";
    else cout <<"Composite.";
    return 0;
}