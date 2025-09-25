#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fastIo()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
#define For(i, n) for (int i = 0; i < n; i++)
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, k;

int a[15][15];

int p, q, l, x;

// cctv 번호 ,위치
vector<pair<int, pair<int, int>>> cctv;

int result = INT_MAX;
void check()
{
  int ret = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 0)
      {
        ret++;
      }
    }
  }

  result = min(result, ret);
}

void spread(pair<int, int> cctv_location, vector<int> dir)
{
  int y, x;
  tie(y, x) = cctv_location;

  for (int direction : dir)
  {
    // 위로 뻗기
    if (direction == 0)
    {
      for (int i = y; i >= 0; i--)
      {
        if (a[i][x] == 6)
          break;
        if (a[i][x] == 0)
        {
          a[i][x] = 7;
        }
      }
    }
    else if (direction == 2)
    {
      for (int i = y; i < n; i++)
      {
        if (a[i][x] == 6)
          break;
        if (a[i][x] == 0)
        {
          a[i][x] = 7;
        }
      }
    }
    else if (direction == 3)
    {
      for (int i = x; i >= 0; i--)
      {
        if (a[y][i] == 6)
          break;
        if (a[y][i] == 0)
        {
          a[y][i] = 7;
        }
      }
    }
    else if (direction == 1)
    {
      for (int i = x; i < m; i++)
      {
        if (a[y][i] == 6)
          break;
        if (a[y][i] == 0)
        {
          a[y][i] = 7;
        }
      }
    }
  }
  return;
}

void solve(int cnt)
{
  // 모든 CCTV의 방향을 결정했다면, 사각지대 계산 후 종료
  if (cnt == cctv.size())
  {
    check();
    return;
  }

  int temp_a[15][15];
  memcpy(temp_a, a, sizeof(a));

  auto tv = cctv[cnt];
  int cctv_idx = tv.first;
  pair<int, int> cctv_location = tv.second;

  // 각 CCTV 종류별로 가능한 모든 방향을 시도
  if (cctv_idx == 1)
  {
    for (int i = 0; i < 4; i++)
    {
      spread(cctv_location, {(i)});
      solve(cnt + 1);
      // 다음 방향을 시도하기 전, 맵 상태를 완벽하게 원상복구
      memcpy(a, temp_a, sizeof(a));
    }
  }
  else if (cctv_idx == 2)
  {
    vector<vector<int>> v = {{1, 3}, {0, 2}}; // 좌우, 상하
    for (auto V : v)
    {
      spread(cctv_location, V);
      solve(cnt + 1);
      memcpy(a, temp_a, sizeof(a));
    }
  }
  else if (cctv_idx == 3)
  {
    vector<vector<int>> v = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    for (auto V : v)
    {
      spread(cctv_location, V);
      solve(cnt + 1);
      memcpy(a, temp_a, sizeof(a));
    }
  }
  else if (cctv_idx == 4)
  {
    // 기존 코드에서 누락되었던 방향 {3, 0, 1} 추가
    vector<vector<int>> v = {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}};
    for (auto V : v)
    {
      spread(cctv_location, V);
      solve(cnt + 1);
      memcpy(a, temp_a, sizeof(a));
    }
  }
  else if (cctv_idx == 5)
  {
    spread(cctv_location, {0, 1, 2, 3});
    solve(cnt + 1);
    // 5번 CCTV는 방향이 1개뿐이지만, 다음 재귀 단계로 넘어갔다 돌아올 때를 대비해
    // 일관성을 위해 상태 복원 코드를 넣어줍니다.
    memcpy(a, temp_a, sizeof(a));
  }
}

int main()
{
  cin >> n >> m;

  For(i, n)
  {
    For(j, m)
    {
      cin >> a[i][j];
      if (a[i][j] != 0 && a[i][j] != 6)
      {
        cctv.push_back({a[i][j], {i, j}});
      }
    }
  }

  solve(0);

  cout << result;
}