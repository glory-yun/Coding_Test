#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string date[100];
string day[100];
string weather[100];

bool cmp(pair<string,string> p1, pair<string,string>p2){


    return p1.first < p2.first;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> date[i] >> day[i] >> weather[i];
    }
    // Please write your code here.

    vector<pair<string,string>> p;

    for(int i=0; i<n;i++){
        if(weather[i] == "Rain"){
            p.push_back({date[i], day[i]});
        }
    }

    sort(p.begin(), p.end(),cmp);

    cout << p[0].first << " " << p[0].second << " " << "Rain";

    return 0;
}