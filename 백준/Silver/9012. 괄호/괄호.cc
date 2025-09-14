#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	while (n--)
	{
		string str; cin >> str;

		stack<char> s;
		
		for (auto ch : str)
		{
			if (ch == '(') s.push(ch);
			else if (ch == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else s.push(ch);
			}
		}

		if (s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


}