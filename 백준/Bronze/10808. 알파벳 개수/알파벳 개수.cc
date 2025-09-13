#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v(26,0);

	string s; cin >> s;

	for (char c : s)
	{
		int idx = c; 
		if (97 <= idx && idx <= 122)
		{
			v[idx%97]++;
		}
	}

	for (auto e : v) cout << e << " ";
}
