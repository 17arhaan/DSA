#include <iostream>
using namespace std;

float returnSum(float a , float b){
    return a + b;
}

int main() {
    float a,b;
    cout << "Enter Two Numbers : ";
    cin >> a >> b;
    float sum = returnSum(a,b);
    cout << " Sum : " << sum;
    return 0;
}
