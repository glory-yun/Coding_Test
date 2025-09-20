#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // memset을 위해 추가
#include <climits> // INT_MAX를 위해 추가

using namespace std;

#define For(i, n) for (int i = 0; i < n; i++)

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
int n, m;

int a[105][105];
int Visit[105][105]; // Visit -> visit 소문자로 변경 (C++ 키워드와 혼동 방지)

bool noCheese()
{
  For(i, n)
  {
    For(j, m)
    {
      if (a[i][j])
        return false;
    }
  }

  return true;
}

void bfs()
{
  Visit[0][0] = 1;
  queue<pair<int, int>> q;
  q.push({0, 0});

  while (q.size())
  {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m)
        continue;

      if (a[ny][nx] == 1)
      {
        Visit[ny][nx]++;
        continue;
      }

      if (Visit[ny][nx])
        continue;

      q.push({ny, nx});
      Visit[ny][nx] = 1;
    }
  }
}

void melt()
{

  memset(Visit, 0, sizeof(Visit));
  bfs();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (Visit[i][j] >= 2)
      {
        a[i][j] = 0;
      }
    }
  }

  return;
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

  int count = 0;

  while (!noCheese())
  {
    count++;
    melt();
  }

  cout << count;
}