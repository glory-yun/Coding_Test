#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for (int i = 0; i < n; i++)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k;

int a[505];

int length[505];

int main()
{
  cin >> n;

  For(i, n)
  {
    int p, q;
    cin >> p >> q;
    a[p] = q;
  }

  int ret = 0;
  for (int i = 1; i <= 505; i++)
  {
    if (!a[i])
      continue;
    length[i] = 1;
    for (int j = 1; j < i; j++)
    {
      if (a[j] < a[i])
      {
        length[i] = max(length[j] + 1, length[i]);
        ret = max(ret, length[i]);
      }
    }
  }

  cout << n - ret;
  // 8 2 9 1 4 6 7 10
}