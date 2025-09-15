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

int a[105][105];
int Visit[105][105];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<int> v[10005];
vector<int> ret;

int visited[10005];

int dfs(int now)
{
    int ret = 1;
    visited[now] = 1;

    for (auto next : v[now])
    {
        if (!visited[next])
        {
            ret += dfs(next);
        }
    }

    return ret;
}

int main()
{

    cin >> n >> m;

    int p, q;
    FOR(i, m)
    {
        cin >> p >> q;
        v[q].push_back(p);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        ret.push_back((dfs(i)));
    }

    int M = *max_element(ret.begin(), ret.end());

    FOR(i, n)
    {
        if (ret[i] == M)
            cout << i + 1 << " ";
    }
}
