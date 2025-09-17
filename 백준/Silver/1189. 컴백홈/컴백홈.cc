#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

void START()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
typedef long long ll;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

ll n, m, k, c, r;

char a[6][6];
int Visit[6][6];

vector<int> ret;

void dfs(int y, int x, int len)
{
   
    if (y == 0 && x == c - 1)
    {
        ret.push_back(len);

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c)
            continue;
        if (Visit[ny][nx] || a[ny][nx] == 'T')
            continue;

        Visit[ny][nx] = 1;
        dfs(ny, nx, len + 1);
        Visit[ny][nx] = 0;
    }

    return;
}

int main()
{
    cin >> r >> c >> k;

    FOR(i, r)
    {
        FOR(j, c)
        {
            cin >> a[i][j];
        }
    }
    Visit[r - 1][0] = 1;
    dfs(r - 1, 0, 1);

    // 거리가 k인 가짓수 출력
    int cnt = 0;
    for (auto e : ret)
    {
        if (e == k)
            cnt++;
    }

    cout << cnt;
}