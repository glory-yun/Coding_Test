#include <bits/stdc++.h>
#include <unordered_map>
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
int main()
{
	int n, m, k,j;
	cin >> n >> m >> k;

	int first = 1, end = m; // 바구니

	int cnt = 0 , dist;
	while (k--)
	{
		cin >> j;

		if (first <= j && j <= end) {
			continue;
		}
		else if (end < j) {
			dist = j - end;
			cnt += dist;
			first += dist;
			end += dist;

			continue;
		} 
		else if (j < first) {
			dist = first - j;
			cnt += dist;
			first -= dist;
			end -= dist;

			continue;
		}
	}
	cout << cnt;
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


bool is_pw(string str)
{
	string gather = "aeiou";

	// 모음이 없을때
	int gather_cnt = 0;
	for (auto ch : gather)
		if (str.find(ch) != -1) gather_cnt++;
	if (!gather_cnt) return false;

	//모음, 자음 연속 3개 x
	int g_cnt = 0, c_cnt = 0;
	for (auto ch : str)
	{
		if (gather.find(ch) != -1) {
			g_cnt++;
			c_cnt = 0;
		}
		else {
			g_cnt = 0;
			c_cnt++;
		}

		if (g_cnt == 3 || c_cnt == 3) return false;
	}

	//ee,oo 빼고 같은 글자 연속 2번 x

	stack<char> stk;

	for (auto ch : str)
	{
		if (stk.empty()) stk.push(ch);
		else if (stk.top() != ch || stk.top() == 'e' || stk.top() == 'o')
		{
			stk.pop();
			stk.push(ch);
		}
		else if (stk.top() == ch) stk.push(ch);
		if (stk.size() == 2) return false;
	}
	return true;
}

int main()
{
	string str; 

	while (cin >> str)
	{
		if (str == "end") break;
		if (is_pw(str)) cout << "<" << str << "> is acceptable." << endl;
		else cout << "<" << str << "> is not acceptable." << endl;
	}

}