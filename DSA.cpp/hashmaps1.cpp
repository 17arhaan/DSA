#include <iostream>
#include<unordered_map>
using namespace std;

void print(unordered_map<int,string>um){
    for(auto i : um){
        cout << i.first << " " << i.second
        << endl;
    }
}
int main(){
    unordered_map<int,string> um1;
    unordered_map<int,string> um2 =
    {
        {1 , "Arhaan"},
        {2 , "Brhaan"},
        {3 , "Crhaan"},
        {4 , "Drhaan"},
    };
    print(um2);
    return 0;
}