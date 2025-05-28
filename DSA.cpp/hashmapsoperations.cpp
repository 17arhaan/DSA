#include <iostream>
#include <unordered_map>
using namespace std;
void print(unordered_map<int,string>um){
    for(auto i : um){
        cout << i.first << " " << i.second
        << endl;
    }
}
int main(){
    unordered_map<int,string> hm;

    hm[1] = "Arhaan";
    hm[2] = "Brhaan";
    hm[3] = "Crhaan";
//! Insertion
    hm.insert({4 , "Drhaan"});
    cout << "After Insertion --------> " << endl;
    print(hm);
//! Accessing
    cout << "Accessing Element 2 ----> " << endl;
    // cout << hm[2];
    cout << hm.at(2) << endl;
//! Updation
    hm[2] = "Zrhaan";
    cout << "After Updation at 3 ----->" << endl;
    cout << hm[2] << endl;
//! Searching
    cout << "Searching 'Zrhaan' ------>" << endl;
    auto it = hm.find(2);
    if(it != hm.end()) {
        cout << " Found at key : " <<it->first << " with value : " << it -> second << endl;
    }
//! Traversing
    cout << "Traversing Elements ----->" << endl;
    for(auto i = hm.begin() ; i != hm.end() ; i++){
        cout << i->first << ": " << i->second << endl;
    }
//! Deleting
    cout << "Deleting Element at 2 --->" << endl;
    hm.erase(2);
    // hm.erase(hm.begin());
    print(hm);
    return 0;
}