#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for (int i = 0; i < n; i++)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k;

int a[1005];

int main()
{
  cin >> n;
  For(i, n) cin >> a[i];

  vector<int> lis;
  vector<int> lis_index(n);

  for (int i = 0; i < n; i++)
  {
    if (lis.empty() || lis.back() < a[i])
    {
      lis.push_back(a[i]);
      lis_index[i] = lis.size() - 1;
    }

    auto iter = lower_bound(lis.begin(), lis.end(), a[i]);
    *iter = a[i];
    lis_index[i] = iter - lis.begin();
  }

  cout << lis.size() << endl;

  vector<int> ret;
  int len = lis.size() - 1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (len == lis_index[i])
    {
      ret.push_back(a[i]);
      len--;
    }
  }

  reverse(ret.begin(), ret.end());
  for (auto e : ret)
    cout << e << " ";
}