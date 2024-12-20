#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int factt = 1;
    for (int i = 1 ; i <= num ; i ++){
        factt *= i;

    cout << "Factorial : " << factt << endl;
    return 0;
}
