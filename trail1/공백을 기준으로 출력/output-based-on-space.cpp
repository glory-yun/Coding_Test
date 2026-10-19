#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> split(string str){

    vector<string> ret;

    int start =0; 
    int back = str.find(" ");

    while(back != string::npos){

        ret.push_back(str.substr(start, back-start));

        start = back + 1;
        back = str.find(" " , start);
    }

    ret.push_back(str.substr(start));

    return ret;
}
int main() {
    string s1,s2;

    getline(cin,s1);
    getline(cin,s2);

    auto v1 = split(s1);
    auto v2 = split(s2);

    string ret = "";

    for(auto s : v1) ret +=s;
    for(auto s : v2) ret +=s;

    cout << ret ;
    return 0;
}