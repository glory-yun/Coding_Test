#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    string str; cin >> str;

    stack<char> stk;

    for(int i=0; i<str.size();i++){
        if(i % 2 == 1){
            stk.push(str[i]);
        }
    }
    
    while(stk.size()){
        cout << stk.top();
        stk.pop();
    }

}