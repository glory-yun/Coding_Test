#include <bits/stdc++.h>
using namespace std;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

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
/*
int r, c;
char a[30][30];
int Visit[200];
int visitf[25][25];
int m = -1;

vector<int> v;

void dfs(int sy, int sx, int dp)
{
	Visit[a[sy][sx]] = 1; visitf[sy][sx] = 1;
	int dis = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = sy + dy[i], nx = sx + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visitf[ny][nx] || Visit[a[ny][nx]]) continue;

		Visit[a[ny][nx]] = 1; visitf[ny][nx] = 1;
		dfs(ny, nx, ++dp);
		Visit[a[ny][nx]] = 0; visitf[ny][nx] = 0; --dp;
	}

	m = max(m, dp);

}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	dfs(0, 0, 0);
	 cout << m +1<< endl;
}
*/
/*
int n;
int a[15][15];

void plant(int y, int x)
{

}

void bfs(int sy, int sx)
{

}

void solve()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		}
	}
}

int main()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	solve();
	//하나하나 방문하면서 
}
*/

int n, k;
int Visit[2000000];
int cnt[2000000];

int main() {
	cin >> n >> k;

	queue<int> q;
	q.push(n); Visit[n] = 1; cnt[n] = 1;

	while (q.size())
	{
		int now = q.front(); q.pop();
		
		for (auto next : { now + 1,now - 1,now * 2 })
		{
			if (0 <= next && next <= 100000)
			{
				if (!Visit[next]) {
					q.push(next);
					Visit[next] = Visit[now] + 1;
					cnt[next] += cnt[now];
				}
				else if (Visit[next] == Visit[now] + 1) {
					cnt[next] += cnt[now];
				}
			}
		}
	}

	cout << Visit[k] - 1 << endl << cnt[k];
}