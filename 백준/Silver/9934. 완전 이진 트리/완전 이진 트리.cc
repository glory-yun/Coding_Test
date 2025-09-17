//int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
#include <bits/stdc++.h>
using namespace std;
/*
1874
vector<int> v;
stack<int> stk;
vector<char> vc;

void check()
{
	while (!stk.empty()) {
		if (stk.top() != v[0]) return;
		else {

				stk.pop();
				vc.push_back('-');
				v.erase(v.begin() );
		}
	}
}
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		v.push_back(k);
	}

	for (int i = 1; i <= n; i++)
	{
		stk.push(i);
		vc.push_back('+');
		check();
	}

	if (!stk.empty()) cout << "NO";
	else {
		for (auto e : vc) cout << e << endl;
	}
}
*/
/*
int main()
{
	int n; cin >> n; vector<int > ret;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		ret.push_back(a);
	}

	stack<int> stk;
	for (auto k : ret)
	{
		if (stk.empty()) stk.push(k);
		else if (!stk.empty() && stk.top() >= k) stk.push(k);
		else if (!stk.empty() && stk.top() < k)
		{
			while (!stk.empty()) {
				int idx = find(ret.begin(), ret.end(), k) - ret.begin();

				if (!stk.empty() && stk.top() < k) {
					ret[idx] = k;
					stk.pop();
				}
				else {
					ret[idx] = -1;

					break;
				}
			}
			stk.push(k);
		}
	}

	ret.push_back(-1);

	for (auto e : ret) cout << e << " ";
}*/
/*
int n;
vector<int> v(3,0);
vector<int> mutal = { 9,3,1 };
int go(int a, int b, int c, int dp)
{
	

	if (a <= 0 && b <= 0 && c <= 0) {
		return dp;
	}
	int ret = 9999;

	if (b <= 0 && c <= 0) ret = min(ret, go(a - 9, b - 3, c - 1, ++dp));
	else if (a <= 0 && c <= 0) ret = min(ret, go(a - 3, b - 9, c - 1, ++dp));
	else if (a <= 0 && b <= 0) ret = min(ret, go(a - 1, b - 3, c - 9, ++dp));
	else if (a <= 0) {
		if(b>c)ret = min(ret, go(a - 1, b - 9, c - 3, ++dp));
		else ret = min(ret, go(a - 1, b - 3, c - 9, ++dp));
	}
	else if (b <= 0) {
		if(a>c)ret = min(ret, go(a - 9, b - 1, c - 3, ++dp));
		else ret = min(ret, go(a - 3, b - 1, c - 9, ++dp));
	}
	else if (c <= 0) {
		if(a>b)ret = min(ret, go(a - 9, b - 3, c - 1, ++dp));
		else ret = min(ret, go(a - 3, b - 9, c - 1, ++dp));
	}
	else {
		ret = min(ret, go(a - 9, b - 3, c - 1, ++dp)); --dp;
		ret = min(ret, go(a - 9, b - 1, c - 3, ++dp)); --dp;
		ret = min(ret, go(a - 3, b - 9, c - 1, ++dp)); --dp;
		ret = min(ret, go(a - 3, b - 1, c - 9, ++dp)); --dp;
		ret = min(ret, go(a - 1, b - 9, c - 3, ++dp)); --dp;
		ret = min(ret, go(a - 1, b - 3, c - 9, ++dp)); --dp;
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int answer = go(v[0], v[1], v[2] , 0);

	cout << answer;
}
*/

int N = 0; int T = 0;
void bfs(vector<int> tree)
{
	queue<vector<int>> q; q.push(tree);

	while (q.size())
	{
		auto root = q.front(); q.pop();

		if (root.size() == 1) {
			cout << root[0] << " ";
			continue;
		}

		int idx = root.size() / 2; 
		
		cout << root[idx] << " "; T++;

		if (T >= pow(2,N)) {
			cout << endl; N++; T = 0;
		}


		vector<int> left((root.size() - 1) / 2), right((root.size() - 1) / 2);
		copy(root.begin(), root.begin() + idx, left.begin());
		copy(root.begin() + idx + 1, root.end(), right.begin());

		q.push(left); q.push(right);

	}

}


int main() {
	int k,n; cin >> k; vector<int> v;
	for (int i = 0; i < pow(2, k) - 1; i++) {
		cin >> n;
		v.push_back(n);
	}

	bfs(v);
}