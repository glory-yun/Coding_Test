
#include <bits/stdc++.h>
using namespace std;
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
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (Visit[ny][nx] || v[ny][nx] == 0) continue;
			Visit[ny][nx] = Visit[y][x] + 1;
			q.push({ ny,nx });

		}
	}

	cout << Visit[n-1][m-1];

	return 0;
}