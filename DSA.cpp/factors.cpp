#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main(){

    int n;
    printf("Enter Number : ");
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i ++){
        if(n%i==0){
            cout << i ;
            cout << endl;
        }
    }
    return 0;
}