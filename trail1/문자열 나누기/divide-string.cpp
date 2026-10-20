#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string str = "";

    for(int i=0; i<n;i++){
        string s;
        cin >> s;
        str += s;
    }

    int idx =0; 
    int start=0, end =0;
    while(idx < str.size()){

        cout << str.substr(idx,5) << endl;
        idx += 5;

    }


    return 0;
}