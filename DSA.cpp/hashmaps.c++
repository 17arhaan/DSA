#include <iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> uMap;
    uMap["Apple"] = 10;
    uMap["Mango"] = 20;
    uMap["Cherry"] = 30;
    for (auto it : uMap)
            cout << it.first << " " << it.second << endl;

        return 0;
}