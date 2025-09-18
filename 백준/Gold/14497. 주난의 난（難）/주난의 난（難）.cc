#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k;

int X1, Y1, X2, Y2;
char a[305][305];
int Visit[305][305];

// 파동으로 초코파 찾기

bool flag = true;
void bfs()
{
    memset(Visit, 0, sizeof(Visit));
    Visit[Y1 - 1][X1 - 1] = 1;

    queue<pair<int, int>> pq;
    pq.push({Y1 - 1, X1 - 1});

    while (pq.size())
    {
        int y, x;
        tie(y, x) = pq.front();
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (Visit[ny][nx])
                continue;

            if (a[ny][nx] == '#')
            {
                flag = false;
                return;
            }

            if (a[ny][nx] == '1')
            {
                Visit[ny][nx] = 1;
                a[ny][nx] = '0';
                continue;
            }

            if (a[ny][nx] == '0')
            {
                Visit[ny][nx] = 1;
                pq.push({ny, nx});
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    cin >> Y1 >> X1 >> Y2 >> X2;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = s[j];
        }
    }

      int cnt = 0;
    while (flag)
    {
        cnt++;
        bfs();
    }
    cout << cnt;
}