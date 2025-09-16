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


int r, c;
char a[1500][1500];
pair<int, int> J;
vector<pair<int, int>> f;
int visitf[1500][1500], visitj[1500][1500];

void fire(vector<pair<int,int>> f)
{
	fill(&visitf[0][0], &visitf[0][0] + 1500 * 1500, -1);
	queue<pair<int, int>> q;
	for (auto e : f) {
		q.push({ e.first, e.second });
		visitf[e.first][e.second] = 1;
	}


	while (!q.empty())
	{
		int y, x; tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visitf[ny][nx] != -1 || a[ny][nx] == '#') continue;
			q.push({ ny,nx }); visitf[ny][nx] = visitf[y][x] + 1;
		}
	}
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x }); visitj[y][x] = 1;

	while (q.size())
	{
		int Y, X; tie(Y, X) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = Y + dy[i], nx = X + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visitj[ny][nx] || a[ny][nx] == '#') continue;
			if (visitf[ny][nx] != -1 && visitj[Y][X] + 1 >= visitf[ny][nx]) continue;
			
			q.push({ ny,nx }); 
			visitj[ny][nx] = visitj[Y][X] + 1;
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'J') {
				J.first = i; J.second = j;
			}
			if (a[i][j] == 'F') f.push_back({ i,j });
		}
	}
	fire(f);
	bfs(J.first, J.second);

	int ret = 9999999;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == r-1 || j == c-1 || i ==0 || j ==0) {
				if (visitj[i][j] != 0) {
					ret = min(ret, visitj[i][j]);
				}
			}
		}
	}

	if (ret != 9999999)cout << ret;
	else cout << "IMPOSSIBLE";
}