#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    string s; 
    int cnt =0;
    vector<string> v;

    while((cin>> s) && s != "0"){
        if(cnt++ %2 ==0) v.push_back(s);
    }
    cout << cnt << endl;
    for(auto str : v) cout << str << endl;

    return 0;
}