#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // memset을 위해 추가
#include <climits> // INT_MAX를 위해 추가

using namespace std;

#define For(i, n) for (int i = 0; i < n; i++)

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m;

int a[505][505];
int Visit[505][505]; // Visit -> visit 소문자로 변경 (C++ 키워드와 혼동 방지)

int ret = -1;

void dfs(int y, int x, int cnt, int sum)
{

  int Sum = sum;
  if (cnt == 4)
  {
    ret = max(ret, sum);
    return;
  }

  Visit[y][x] = 1;
  Sum += a[y][x];

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i], nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
      continue;

    if (Visit[ny][nx])
      continue;

    dfs(ny, nx, cnt + 1, Sum);
  }

  Visit[y][x] = 0;
  Sum -= a[y][x];

  return;
}

void othershape(int y, int x)
{
  // ㅓ
  if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < n)
    ret = max(ret, a[y][x - 1] + a[y - 1][x] + a[y][x] + a[y + 1][x]);
  // ㅏ
  if (x + 1 < m && y - 1 >= 0 && y + 1 < n)
    ret = max(ret, a[y][x + 1] + a[y - 1][x] + a[y][x] + a[y + 1][x]);
  // ㅗ
  if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < m)
    ret = max(ret, a[y][x - 1] + a[y - 1][x] + a[y][x] + a[y][x + 1]);
  // ㅜ
  if (x - 1 >= 0 && y + 1 < n && x + 1 < m)
    ret = max(ret, a[y][x - 1] + a[y + 1][x] + a[y][x] + a[y][x + 1]);
}

int main()
{
  cin >> n >> m;

  For(i, n)
  {
    For(j, m)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      dfs(i, j, 0, 0);
      othershape(i, j);
    }
  }

  cout << ret;
}

// 3 3
// 2 1 2
// 1 2 1
// 2 1 2