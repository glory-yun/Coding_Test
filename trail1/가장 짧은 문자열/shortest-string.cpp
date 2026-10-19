#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    
    int mn = 25, mx = -1;
    for(int i=0; i<3;i++){
        string str; cin >> str;
        mn = min(mn, (int)str.size());
        mx = max(mx, (int)str.size());
    }

    cout << mx - mn;    
    return 0;
}