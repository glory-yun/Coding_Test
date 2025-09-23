#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for (int i = 0; i < n; i++)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k;

int a[1005];

int length[505];

int main()
{
  cin >> n;
  For(i, n) cin >> a[i];

  vector<int> lis;

  for (int i = 0; i < n; i++)
  {
    if (lis.empty() || lis.back() < a[i])
    {
      lis.push_back(a[i]);
    }

    auto iter = lower_bound(lis.begin(), lis.end(), a[i]);
    *iter = a[i];
  }

  cout << lis.size();
}