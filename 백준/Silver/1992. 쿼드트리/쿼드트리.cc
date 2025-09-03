#include <bits/stdc++.h>
using namespace std;
/*
int n, m;
vector<pair<int, int>> L, W;
int v[51][51],Visit[51][51];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int ret = -1;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;

	q.push({ y,x });
	Visit[y][x] = 1;

	while (!q.empty())
	{
		auto Q = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = Q.first + dy[i], nx = Q.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (v[ny][nx] == 0 || Visit[ny][nx] != 0) continue;
			
			Visit[ny][nx] = Visit[Q.first][Q.second] + 1;
			q.push({ ny,nx });
		}
	}
}
void solve(pair<int,int> fst, pair<int, int> sec)
{
	fill(&Visit[0][0], &Visit[0][0] + 51 * 51, 0);
	bfs(fst.first, fst.second);
	ret = max(ret, Visit[sec.first][sec.second]);
}

int main()
{
	string str;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'L') { L.push_back({ i,j }); v[i][j] = 1; }
			else {
				W.push_back({ i,j }); v[i][j] = 0;
			}
		}
	}

	

	for (int fst = 0; fst < L.size(); fst++) {
		for (int sec = fst + 1; sec < L.size(); sec++) {
			solve(L[fst],L[sec]);
		}
	}

	cout << ret-1;
}
*/
/*
int n, m;
int total, k;
int Visit[100][100];
vector<pair<int, int>> city, chicken;
int ret = 999999;

void solve(vector<pair<int, int>> combi_vec)
{
	int sum = 0;
	for (int i = 0; i < city.size(); i++)
	{
		int temp = 999999;
		for (int j = 0; j < combi_vec.size(); j++)
		{
			int r1, c1, r2, c2;
			tie(r1, c1) = city[i]; tie(r2, c2) = combi_vec[j];

			temp = min(temp,abs(r1 - r2) + abs(c1 - c2));
		}
		sum += temp;
	}
	ret = min(ret, sum);
}
int cnt = 0;
void combi(int start, vector<int> b)
{
	if (b.size() == m) {
		vector<pair<int, int>> combi_vec;
		for (auto idx : b) {
			combi_vec.push_back(chicken[idx]); //조합으로 만들어진 인덱스로 chicken뽑기
		}
		solve(combi_vec);
	}
	for (int i = start + 1; i < total; i++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}
int main()
{
	cin >> n >> m; //치킨집 m개 뽑기
	int e;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> e;
			if (e == 1)city.push_back({ i,j });
			else if (e == 2)chicken.push_back({ i,j });
		}
	}
	total = chicken.size();

	vector<int> b;
	combi(-1, b);
	cout << ret;
}
*/

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
int go(int a, int b, int c , int dp)
{
	int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;

	if (a <= 0 && b <= 0 && c <= 0) {
		return dp;
	}
	dp++;

	A = go(a - 9, b - 3, c - 1, dp),
	B = go(a - 9, b - 1, c - 3, dp),
	C = go(a - 3, b - 9, c - 1, dp),
	D = go(a - 3, b - 1, c - 9, dp),
	E = go(a - 1, b - 9, c - 3, dp),
	F = go(a - 1, b - 3, c - 9, dp);


	return dp;
}

int main()
{
	int a, b, c;
	cin >> a >>b >>c;

	int ret = go(a, b, c, 0);

	cout << ret;
}
*/
/*
int n, m;
int v[105][105];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int Visit[105][105];


int main()
{
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			v[i][j] = str[j] - '0';
		}
	}
	queue<pair<int, int>> q;

	Visit[0][0] = 1;
	q.push({ 0,0 });

	while (!q.empty())
	{
		int y, x;
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || ny >= m) continue;
			if (Visit[ny][nx] || v[ny][nx] == 0)continue;
			Visit[ny][nx] = Visit[y][x] + 1;
			q.push({ ny,nx });

		}
	}

	cout << Visit[n-1][m-1];

	return 0;
}
*/

int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int n, v[100][100], Visit[100][100];
int x, y;

void go(int start_y, int start_x, int N)
{
	if (N == 1) {
		cout << v[start_y][start_x];
		return;
	}
	int cnt0 = 0, cnt1 = 0;
	if (v[start_y][start_x]) cnt1++; else cnt0++;
	queue<pair<int, int>> q;
	fill(&Visit[0][0], &Visit[0][0] + 100 * 100, 0);

	q.push({ start_y,start_x });
	Visit[start_y][start_x] = 1;

	while (!q.empty())
	{
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < start_y || nx < start_x || ny >= start_y+ N || nx >= start_x+ N) continue;
			if (Visit[ny][nx] == 1) continue;
			if (v[ny][nx] == 1) cnt1++;
			else if(v[ny][nx] == 0) cnt0++;

			Visit[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	if (cnt1 == 0) { cout << 0; }
	else if (cnt0 == 0) { cout << 1; }
	else {
		cout << "(";
		go(start_y, start_x, N / 2);
		go(start_y, start_x + N/2, N / 2);
		go(start_y + N/2, start_x, N / 2);
		go(start_y + N / 2, start_x + N / 2, N / 2);
		cout << ")";
	}
}

int main()
{
	string str; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			v[i][j] = str[j] - '0';
		}
	}

	go(0 , 0, n);

}