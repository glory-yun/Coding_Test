#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for (int i = 0; i < n; i++)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k;

bool ableMove(int ny, int nx)
{
  if (ny < 0 || nx < 0 || ny >= n || ny >= m)
    return false;

  return true;
}
int arr[25][25];
int Visit[25][25];

int result = -1;

vector<int> operate(vector<int> v)
{
  vector<int> ret;
  for (int i = 0; i < v.size(); i++)
  {
    if (i != v.size() - 1 && v[i] == v[i + 1])
    {
      result = max(result, v[i] * 2);
      ret.push_back(v[i] * 2);
      i += 1;
    }
    else
    {
      result = max(result, v[i]);
      ret.push_back(v[i]);
    }
  }

  return ret;
}

void Sum(int dir, int a[25][25])
{

  // 상
  if (dir == 0)
  {
    for (int col = 0; col < n; col++)
    {
      vector<int> v;
      for (int row = 0; row < n; row++)
      {
        if (a[row][col] != 0)
          v.push_back(a[row][col]);
      }
      auto ret = operate(v);

      for (int i = 0; i < n; i++)
      {
        if (ret.size() > i)
          a[i][col] = ret[i];
        else
          a[i][col] = 0;
      }
    }
  }
  // 우
  if (dir == 1)
  {
    for (int row = 0; row < n; row++)
    {
      vector<int> v;
      for (int col = n - 1; col >= 0; col--)
      {
        if (a[row][col] != 0)
          v.push_back(a[row][col]);
      }

      auto ret = operate(v);

      // 합친 배열을 다시 행에 뿌리기
      for (int i = n - 1; i >= 0; i--)
      {
        if (ret.size() > n - 1 - i)
          a[row][i] = ret[n - 1 - i];
        else
          a[row][i] = 0;
      }
    }
  }
  // 하
  if (dir == 2)
  {
    for (int col = 0; col < n; col++)
    {
      vector<int> v;
      for (int row = n - 1; row >= 0; row--)
      {
        if (a[row][col] != 0)
          v.push_back(a[row][col]);
      }
      auto ret = operate(v);

      for (int i = n - 1; i >= 0; i--)
      {
        if (ret.size() > n - 1 - i)
          a[i][col] = ret[n - 1 - i];
        else
          a[i][col] = 0;
      }
    }
  }
  // 좌
  if (dir == 3)
  {
    for (int row = 0; row < n; row++)
    {
      vector<int> v;
      // 한 행에 있는 모든 숫자 넣기
      for (int col = 0; col < n; col++)
      {
        if (a[row][col] != 0)
          v.push_back(a[row][col]);
      }

      // 숫자만 있는 배열을 가지고 합친 배열 받기
      auto ret = operate(v);

      // 합친 배열을 다시 행에 뿌리기
      for (int i = 0; i < n; i++)
      {
        if (ret.size() > i)
          a[row][i] = ret[i];
        else
          a[row][i] = 0;
      }
    }
  }
}

void dfs(int cnt, int dir, int arr[25][25])
{
  if (cnt == 6)
  {
    return;
  }

  // 복사 배열 만들기
  int a[25][25];
  For(i, n)
  {
    For(j, n) { a[i][j] = arr[i][j]; }
  }

  // dir에 따라 숫자합치기
  Sum(dir, a);

  // 숫자를 합친 뒤 이동
  for (int i = 0; i < 4; i++)
  {
    dfs(cnt + 1, i, a);
  }

  return;
}

int main()
{

  cin >> n;

  For(i, n)
  {
    For(j, n)
    {
      cin >> arr[i][j];
    }
  }

  int cnt = 0;
  for (int dir = 0; dir < 4; dir++)
  {
    dfs(cnt + 1, dir, arr);
  }

  cout << result;
}