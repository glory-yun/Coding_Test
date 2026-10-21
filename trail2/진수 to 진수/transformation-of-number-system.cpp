#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int a, b;
string num;
stack<int> stk;
queue<int> q;

int main() {
    cin >> a >> b;
    cin >> num;

    //a진수로 표현된 N 을 B진수로 표현하기
    reverse(num.begin(),num.end());
    int temp = 0;

    for(int i=0; i<num.size();i++){
        temp += (num[i] - '0') * pow(a,i);
    }

    while(true){
        if(temp < b){
            stk.push(temp);
            break;
        }

        stk.push(temp%b);
        temp /= b;
    }

    while(stk.size()){
        cout << stk.top();
        stk.pop();
    }

    return 0;
}