#include <iostream>
#include <cctype>
using namespace std;

int main() {
    // Please write your code here.
    string s1, s2; cin >> s1 >> s2;

    int ret=0;

    
    string str = "";
    
    for(char ch : s1){
        if(isdigit(ch)){
            str+= ch;
        }
        else{
            break;
        }
    }

     if(!str.empty())
        ret += stoi(str);

    str = "";
    for(char ch : s2){
        if(isdigit(ch)){
            str+= ch;
        }
        else{
          
            break;
        }
    }
    if(!str.empty())
        ret += stoi(str);


    cout << ret;
    return 0;
}