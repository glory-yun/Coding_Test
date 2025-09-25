#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fastIo()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
#define For(i, n) for (ll i = 0; i < n; i++)
ll dy[] = {-1, 0, 1, 0};
ll dx[] = {0, 1, 0, -1};
ll n, m, k;

ll a[105][105];

ll p, q, l, x;

vector<ll> A;

ll B, C;

void Input()
{
  cin >> n;
  For(i, n)
  {
    cin >> p;
    A.push_back(p);
  }
  cin >> B >> C;
}

ll solve(ll num)
{

  ll ret = 0;

  num -= B;
  ret++;

  if (num <= 0)
    return 1;

  ll r = num / C;
  ret += (num % C == 0 ? r : r + 1);
  return ret;
}

int main()
{
  Input();

  ll ret = 0;

  for (auto e : A)
  {
    ret += solve(e);
  }

  cout << ret;
}
