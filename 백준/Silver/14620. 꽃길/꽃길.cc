#include <bits/stdc++.h>
using namespace std;
int dy[] = { 0,-1,0,1 }, dx[] = { -1,0,1,0 };
typedef long long ll;
/*
int n;
char a[25][25];
vector<vector<char>> v;
int T = 0, H = 0, ret = 9999999;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'T') T++;
			if (a[i][j] == 'H') H++;
		}
	}

	for (int i = 0; i < n; i++) {
		vector<char> b;
		for (int j = 0; j < n; j++) {
			b.push_back(a[i][j]);
		}
		v.push_back(b);
	}

	for (int i = 0; i < n; i++) {
		vector<char> b;
		for (int j = 0; j < n; j++) {
			b.push_back(a[j][i]);
		}
		v.push_back(b);
	}

	for (int idx = 0; idx < (1 << v.size()); idx++) {
		char arr[25][25]; copy(&a[0][0], &a[0][0] + 25 * 25, &arr[0][0]);

		for (int i = 0; i < 2*n; i++) {
			if (idx & (1 << i)) {
				if (i < n) {
					for (int k = 0; k < n; k++) {
						if (v[i][k] == 'T') arr[i][k] = 'H';
						else arr[i][k] = 'T';
					}
				}
				else {
					for (int k = 0; k < n; k++) {
						if (v[k][i-n] == 'T') arr[k][i-n] = 'H';
						else arr[k][i-n] = 'T';
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'T') sum++;
			}
		}
		ret = min(ret, sum); 
	}


	cout << ret;

}
*/
/*
int main()
{
	int n; cin >> n; 
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		v.push_back(k);
	}

	stack<int> stk;

	int idx = 0, cnt = 0;

	for (int j = 0; j < n-1; j++) 
	{
		for (int i = j; i < n; i++)
		{
			int temp = v[j];

			if (stk.empty()) {
				stk.push(v[i]);
			}
			else if (stk.size() == 1) {
				stk.push(v[i]); cnt++;
			}

			else if (temp >= stk.top() && stk.top() <= v[i]) {
				stk.push(v[i]); cnt++;
			}
			else if (temp < stk.top() || stk.top() > v[i]) {
				while (stk.size()) stk.pop();
				break;
			}

			if (i == n-1) while (stk.size()) stk.pop();
		}

		cout << "cnt "<< j << " : " << cnt << endl;
	}
//	cout << cnt;
}
*/
/*
int change_time(string str)
{
	int h = stoi(str.substr(0, 2)) * 60;
	int s = stoi(str.substr(3));

	return h + s;
}

string change_str(int time)
{

	string h = "", s = "";

	if (time / 60 < 10) {
		h = "0" + to_string(time / 60);
	}
	else {
		h = to_string(time / 60);
	}

	if (time % 60 < 10) {
		s = "0" + to_string(time % 60);
	}
	else {
		s = to_string(time % 60);
	}

	string ret = h + ":" + s;
	

	return ret;

}

int main()
{
	int n; cin >> n;

	int win; string T;

	int t1 = 0, t2 = 0, cnt1 = 0, cnt2 = 0;

	int prev = 0;
	bool flag1 = false, flag2 = false;

	for (int i = 0; i < n; i++)
	{
		cin >> win >> T; int t = change_time(T);
		
		if (win == 1) cnt1++; else cnt2++;
		if (cnt1 > cnt2 &&!flag1) {
			prev = t; flag1 = true;
			continue;
		}
		else if (cnt1 < cnt2 && !flag2) {
			prev = t; flag2 = true;
			continue;
		}

		if (cnt1 >= cnt2)
		{
			t1 += t - prev;

			prev = t;
		}
		else if (cnt1 <= cnt2)
		{
			t2 += t - prev;

			prev = t;
		}

	}

	if (cnt1 < cnt2) t2 += 48 * 60 - prev;
	else t1 += 48 * 60 - prev;
	
	cout << change_str(t1) << endl << change_str(t2);

}
*/


/*
int main()
{
	int n, k; cin >> n >> k;

	vector<int> v(k), box(n);
	for (int i = 0; i < k; i++) cin >> v[i];

	for (int i = 0; i < n; i++) box[i] = v[i];

	int start = n; int cnt = 0;
	while (start + n < k)
	{

		vector<int> extra;
		for (int i = 0; i < n; i++) {
			extra.push_back(v[start + i]);
		}
		sort(extra.begin(), extra.end()); sort(box.begin(), box.end());

		cout << endl;
		for (auto e : box) cout << e << " ";
		cout << endl;
		for (auto e : extra) cout << e << " ";

		for (int i = 0; i < n; i++)
		{
			if (box[i] != extra[i]) {
				box[i] = extra[i];
				cnt++;
			}
		}
	
		start += n;
	}

	cout <<endl<< "start " << start << endl;
}
*/

/*
int main()
{
	ll n, l; cin >> n >> l;
	vector<pair<ll, ll>> v(n);

	for (ll i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

}
*/

/*
* 17143 
int r, c, m, R, C;
int a[105][105], b[105][105];

struct A {
	int S, D, Z;
};
vector<A> v(m + 2);




int answer = 0;
void fish(int col)
{
	for (int i = 1; i <= r; i++) {
		if (a[i][col])
		{
			answer += v[a[i][col]].Z;
			a[i][col] = 0;
			break;
		}
	}
}

void move(int idx)
{
	int ss = v[idx].S, dd = v[idx].D, zz = v[idx].Z;
}

void shark_move()
{
	fill(&b[0][0], &b[0][0] + 105 * 105, 0);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j]) {
				move(a[i][j]);
			}
		}
	}


}

int main()
{
	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++) {
		cin >> R >> C;
		int X, Y, Z; cin >> X >> Y >> Z;
		v.push_back({ X,Y,Z });
		a[R][C] = i; 
	}



	for (int col = 1; col <= c; col++)
	{
		fish(col);
		shark_move();

	}


	
}
*/



int n;
int a[15][15];
int Visit[15][15];


bool check(int y,int x)
{
	if (Visit[y][x]) return 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || Visit[ny][nx]) return 0;
	}

	return 1;
}

int plant(int y, int x)
{
	int sum = 0;
	Visit[y][x] = 1;

	for (int i = 0; i < 4; i++) 
	{
		int ny = y + dy[i], nx = x + dx[i];

		Visit[ny][nx] = 1;
		sum += a[ny][nx];
	}

	return sum + a[y][x];
} 

void pick(int y, int x) 
{
	Visit[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		Visit[ny][nx] = 0;
	}
}

int ret = 9999999;
void dfs(int y, int x, int cnt, int hap)
{
	if (cnt == 3)
	{

	

		ret = min(ret, hap);
		return;
	}

	///////// else

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check(i,j)) continue;

			int h = plant(i, j);
			dfs(i, j, cnt + 1, hap + h);
			pick(i, j);
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}


	dfs(0, 0,0 ,0);

	cout << ret;
}