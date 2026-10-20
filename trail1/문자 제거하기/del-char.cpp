#include <iostream>
using namespace std;

int main() {
    
    string str; cin >> str;
    int n;
    while(str.size() > 1){

        cin >> n;

        if(str.size() > n)
            str.erase(n,1);
        else
            str.pop_back();

        cout << str << endl;

    }

    return 0;
}