#include <iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter Alphabet: ";
    cin>>(ch);
    if (char (ch) >= 65 && char(ch) <= 90){
        cout<<"Capital Alphabet";
    } else {
        cout<<"Small Alphabet";
    }
    return 0;
}