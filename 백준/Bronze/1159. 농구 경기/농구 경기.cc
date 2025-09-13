#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string ret, s;
    map<char, int> mp;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        mp[s[0]]++;
    }

    for(auto m : mp) if(m.second >=5) ret += m.first;
    
    if(ret == "") cout << "PREDAJA"; else cout << ret;
    
}