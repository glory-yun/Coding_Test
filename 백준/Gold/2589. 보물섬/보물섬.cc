#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

void START()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
typedef long long ll;

ll n, m, k;

char a[55][55];
int Visit[55][55];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int result = INT_MIN;
int p, q, M;
char ch;

int bfs(int Y, int X)
{
    int ret = INT_MIN;

    Visit[Y][X] = 1;
    queue<pair<int, int>> pq;
    pq.push({Y, X});

    while (!pq.empty())
    {
        int y, x;
        tie(y, x) = pq.front();
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (Visit[ny][nx] || a[ny][nx] == 'W')
                continue;

            Visit[ny][nx] = Visit[y][x] + 1;
            pq.push({ny, nx});

            ret = max(ret, Visit[ny][nx]);
        }
    }


    return ret;
}

int main()
{

    cin >> n >> m;

    FOR(i, n)
    {

        FOR(j, m)
        {
            cin >> a[i][j];
        }
    }

        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'L')
            {
                memset(Visit, 0, sizeof(Visit));
                result = max(result, bfs(i, j));
            }
        }
    }

    cout << result - 1;
}