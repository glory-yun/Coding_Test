#include <bits/stdc++.h>
using namespace std;
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

int v[10][10], n, m;
int ret = -1;

vector<pair<int, int>> emp, virus;

int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

void dfs(int y, int x , bool visit[][10])
{
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visit[ny][nx] || v[ny][nx] == 1) continue;

		dfs(ny, nx,visit);
	}
}

int solve(bool visit[][10])
{
	fill(&visit[0][0], &visit[0][0] + 10 * 10, 0);
	for (auto v : virus) {
		dfs(v.first, v.second,visit);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0 && v[i][j] == 0) cnt++;
		}
	}
	
	return cnt;
}

int main()
{
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 0) emp.push_back({ i,j });
			if (v[i][j] == 2) virus.push_back({ i,j });
		}
	}

	bool visit[10][10];
	fill(&visit[0][0], &visit[0][0] + 10 * 10, 0);
	
	for (int i = 0; i < emp.size(); i++) {
		for (int j = i + 1; j < emp.size(); j++) {
			for (int k = j + 1; k < emp.size(); k++){
				v[emp[i].first][emp[i].second] = 1;
				v[emp[j].first][emp[j].second] = 1;
				v[emp[k].first][emp[k].second] = 1;

				ret = max(ret, solve(visit));

				v[emp[i].first][emp[i].second] = 0;
				v[emp[j].first][emp[j].second] = 0;
				v[emp[k].first][emp[k].second] = 0;
			} 
		}
	}

	cout << ret;

}
