#include <bits/stdc++.h>
using namespace std;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
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
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
char a[2000][2000];
int r, c;
vector<pair<int, int>> v;
bool meet = false;
int cnt = 0;
int Visit[2000][2000];
pair<int, int> d1, d2;
int melt_visit[2000][2000];

void melt(int y, int x)
{
	queue<pair<int, int>> q;

	q.push({ y,x }); melt_visit[y][x] = 1;

	while (!q.empty())
	{
		int Y, X; tie(Y, X) = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = Y + dy[i], nx = X + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
			if (a[ny][nx] == 'L') continue;
			if (a[ny][nx] == 'X') {
				a[ny][nx] = '.';
				melt_visit[ny][nx] = 1;
				continue;
			}
			else if (!melt_visit[ny][nx] && a[ny][nx] == '.') {
				q.push({ ny,nx });
				melt_visit[ny][nx] = 1;
			}
		}
	}
}

void go(int y, int x)
{
	fill(&Visit[0][0], &Visit[0][0] + 2000 * 2000, 0);
	queue < pair<int, int>> q;

	q.push({ y,x }); Visit[y][x] = 1;

	while (!q.empty())
	{
		int Y, X; tie(Y, X) = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = Y + dy[i], nx = X + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
			if (ny == d2.first && nx == d2.second) {
				meet = true; 
				return;
			}
			if (Visit[ny][nx] || a[ny][nx] == 'X') continue;

			q.push({ ny,nx });
			Visit[ny][nx] = Visit[y][x] + 1;
		}
	}
	cnt++;
}


void solve()
{
	while (true)
	{
		go(d1.first, d1.second); 
		if (meet) {
			cout << cnt;
			break;
		}
		
		//melt
		fill(&melt_visit[0][0], &melt_visit[0][0] + 2000 * 2000, 0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if(!melt_visit[i][j] && a[i][j] == '.') melt(i, j);
			}
		}
		
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') v.push_back({ i,j });
		}
	}

	d1 = v[0]; d2 = v[1];

	solve();
	//백조끼리 만나는지 체크
	// 얼음 녹이기
	//이걸 반복

}

*/

int a[150][150];
int r, c, cnt;
int visitt[150][150];
bool Melt = false;
int ret = 0;

void melt(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push({ sy,sx }); visitt[sy][sx] = 1;

	while (q.size())
	{
		int y, x; tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visitt[ny][nx]) continue;
			if (a[ny][nx] == 1) {
				a[ny][nx] = 0;
				visitt[ny][nx] = 1;
				continue;
			}
			q.push({ ny,nx }); visitt[ny][nx] = 1;

		}
	}

	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j]) sum++;
		}
	}

	if (sum == 0) Melt = true;
	else ret = sum;

}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	int answer = 0;
	while (true)
	{
		fill(&visitt[0][0], &visitt[0][0] + 150 * 150, 0);

		int b = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j]) b++;
			}
		}

		if (b == 0) {
			cout << 0 << endl << 0;
			break;
		}

		else {

			melt(0, 0); answer++;
			if (Melt) {
				cout << answer << endl;
				cout << b;
				break;
			}

		}
	}
}