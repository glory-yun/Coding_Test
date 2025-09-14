#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
void START()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

typedef long long ll;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int t;
int n, m, k;
int x, y;
int a[55][55];
int Visit[55][55];

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    Visit[i][j] = 1;

    while (q.size())
    {
        auto now = q.front();
        q.pop();

        int y = now.first, x = now.second;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny > n || nx > m || !a[ny][nx] || Visit[ny][nx])
                continue;

            Visit[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    START();

    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 55; i++)
            for (int j = 0; j < 55; j++)
                a[i][j] = 0;
        for (int i = 0; i < 55; i++)
            for (int j = 0; j < 55; j++)
                Visit[i][j] = 0;
        int ret = 0;

        cin >> m >> n >> k;

        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1 && !Visit[i][j])
                {
                    bfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << endl;
    }
}