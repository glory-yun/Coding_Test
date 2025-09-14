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

int main()
{
    cin >> n >> m >> k;

    vector<int> v(k);
    FOR(i, k)
    {
        cin >> v[i];
    }

    int start = 1, end = start + m - 1;

    int cnt = 0;
    for (auto idx : v)
    {
        if (start <= idx && idx <= end)
            continue;

        else if (idx < start)
        {
            cnt += start - idx;
            start = idx;
            end = start + m - 1;
        }
        else if (end < idx)
        {
            cnt += idx - end;
            end = idx;
            start = end - m + 1;
        }
    }
    cout << cnt;
}