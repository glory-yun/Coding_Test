#include <bits/stdc++.h>
using namespace std;

void START()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
typedef long long ll;

ll n, m, k;

int a, b, c;

int main()
{
    START();

    cin >> n >> k;

    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> psum;

    psum.push_back(v[0]);

    for (int i = 1; i <= n; i++)
        psum.push_back(psum[i - 1] + v[i]); // 누적합 구현

    vector<int> c;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        c.push_back(psum[i + k - 1] - psum[i - 1]);
    }
    cout << *max_element(c.begin(), c.end());
}

// v[a] ~ v[b] 합 == psum[b] - psum[a-1]