#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
	string str;
	while (1)
	{
		getline(cin, str);

		if (str == "") break;

		stack<char> stk;
		for (auto ch : str)
		{
			if(ch == '(' || ch == '[') stk.push(ch);
			else if (!stk.empty() && ch == ')') {
				if (stk.top() == '(') stk.pop();
				else {
					cout << "no" << endl; break;
				}
			}
			else if (!stk.empty() && ch == ']') {
				if (stk.top() == '[') stk.pop();
				else {
					cout << "no" << endl; break;
				}
			}
		}
		if (stk.empty()) {
			cout << "yes" << endl;
			continue;
		}
		else {
			cout << "no" << endl;
			continue;
		}
	}
}
*/

/*
typedef long long ll;

vector<pair<ll, ll>> mp;


bool cmp(const pair<ll, ll>& a,const pair<ll, ll>& b)
{
	return a.second > b.second;
}
int main()
{
	ll n,c,k ; cin >> n >> c;

	while(n--) {
		cin >> k;
		
	}

	vector<pair<ll, ll>> v(mp.begin(), mp.end());

	sort(v.begin(), v.end(), cmp);

	for (auto V : v)
	{
		for (int i = 0; i < V.second; i++)
			cout << V.first << " ";
	}

}
*/

typedef long long ll;

int main()
{
	int n; cin >> n;

	int num = 666, cnt = 0;

	while (true)
	{
		string s = to_string(num);

		if (s.find("666") == -1) {
			num++;
			continue;
		}

		else {
			cnt++;
			num++;
		}

		if (n == cnt)
		{
			cout << s;
			break;
		}
	}
}