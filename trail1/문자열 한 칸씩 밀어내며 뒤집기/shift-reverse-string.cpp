#include <iostream>
#include <algorithm>

using namespace std;

string str;
int q;

int main() {
    cin >> str >> q;

    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;


        if(query_type == 1){
            char ch = str[0];
            str = str.substr(1) + ch;
            cout << str << endl;
        }
        else if(query_type == 2){
            str = str.back() + str.substr(0, str.size()-1);
            cout << str << endl;
        }
        else{
            reverse(str.begin(), str.end());
            cout << str << endl;
        }


    }

  

    return 0;
}
