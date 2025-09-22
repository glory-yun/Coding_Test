#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for (int i = 0; i < n; i++)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k;
int Visit[4];

bool ableMove(int ny, int nx)
{
  if (ny < 0 || nx < 0 || ny >= n || ny >= m)
    return false;

  return true;
}
int a[4][8];

void rotate(int idx, int dir)
{
  if (dir == 1)
  {
    // 시계방향 톱니 회전
    int tem = a[idx][7];
    for (int i = 7; i >= 1; i--)
    {
      a[idx][i] = a[idx][i - 1];
    }
    a[idx][0] = tem;
  }
  else
  {
    // 반시계 방향 시계회전
    int tem = a[idx][0];
    for (int i = 0; i < 7; i++)
    {
      a[idx][i] = a[idx][i + 1];
    }
    a[idx][7] = tem;
  }
}

// n극 = 1 , s극 = 0
// 시계방향으로 위에서부터 0,1,2,3,4,5,6,7
// idx번째 톱니바퀴에서 i번째 톱니의 상태 저장 (n , s)
// 맞닿는 부분은 2 or 6

void solve(int idx, int dir)
{
  // 처음에는 일단 돌기
  Visit[idx] = 1;

  int leftIsRotate = (a[idx][6] != a[idx - 1][2]);
  int rightIsRotate = (a[idx][2] != a[idx + 1][6]);

  // 이후 왼쪽 돌리기
  if (idx > 0 && !Visit[idx - 1])
  {
    if (leftIsRotate)
    {
      // 다른 극이면 dir * -1

      solve(idx - 1, dir * -1);
    }
  }

  // 이후 오른쪽 돌리기
  if (idx < 4 && !Visit[idx + 1])
  {
    // 극이 다르면 회전

    if (rightIsRotate)
    {
      // 다른 극이면 dir * -1

      solve(idx + 1, dir * -1);
    }
  }

  rotate(idx, dir);

  Visit[idx] = 0;

  return;
}

int main()
{
  string s;
  for (int i = 0; i < 4; i++)
  {
    cin >> s;
    for (int j = 0; j < 8; j++)
    {
      a[i][j] = s[j] - '0';
    }
  }

  cin >> k;
  int idx, dir; // 1이면 시계 -1이면 반시계
  while (k--)
  {
    cin >> idx >> dir;

    // dir = 1 or -1
    solve(idx - 1, dir);
  }

  int sum = 0;
  for (int idx = 0; idx < 4; idx++)
  {
    if (a[idx][0] == 0)
      sum += 0;
    else
    {
      sum += pow(2, idx);
    }
  }

  cout << sum;
}