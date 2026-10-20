#include <iostream>
#include <cctype>
using namespace std;

int main() {
    // Please write your code here.
    string str; cin >> str;

    for(char ch : str){

        if(ch >= 97) cout << (char)toupper(ch);
        else cout << (char)tolower(ch);

    }

    return 0;
}