#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string N;

int main() {
    cin >> N;

    reverse(N.begin(),N.end());

    int temp =0;
    for(int i=0; i<N.size(); i++){
        temp += (N[i] -'0') * pow(2,i);
    } 

    temp *= 17;

    string ret = "";
    while(true){

        if(temp < 2){
            
            ret += to_string(temp);
            break;
        }

            ret += to_string(temp%2);

        temp /=2;

    }

    reverse(ret.begin(), ret.end());
    cout << ret;

    return 0;
}