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

int a[305][305];
int Visit[305][305]; // Visit -> visit 소문자로 변경 (C++ 키워드와 혼동 방지)

queue<pair<int, int>> water;

int visit_ice[305][305];

// 몇덩어리인지 체크
void check(int Y, int X)
{
  // bfs 돌면서 visit 체크
  queue<pair<int, int>> q;
  q.push({Y, X});

  Visit[Y][X] = 1;

  while (q.size())
  {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m || Visit[ny][nx])
        continue;
      if (a[ny][nx] == 0)
        continue;

      Visit[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
  return;
}

bool CheckIce()
{
  int ret = 0;
  memset(Visit, 0, sizeof(Visit));

  For(i, n)
  {
    For(j, m)
    {
      if (!Visit[i][j] && a[i][j] > 0)
      {

        ret++;
        check(i, j);
      }
    }
  }

  if (ret >= 2)
    return true;
  else
    return false;
}

// 얼음이 있는경우
bool isIce()
{
  For(i, n)
  {
    For(j, m)
    {
      if (a[i][j] != 0)
        return true;
    }
  }

  return false;
}

void bfs()
{
  memset(Visit, 0, sizeof(Visit));
  queue<pair<int, int>> nowwater;
  // 1. nowwater 큐에 빼면서, 4방향으로 순찰

  while (water.size())
  {
    auto w = water.front();
    water.pop();
    Visit[w.first][w.second] = 1;
    nowwater.push(w);
  }

  while (nowwater.size())
  {
    int y, x;
    tie(y, x) = nowwater.front();
    Visit[y][x] = 1;
    nowwater.pop();

    bool isMeltIce = false;
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i], nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m)
        continue;
      // 물이면
      if (a[ny][nx] == 0 && Visit[ny][nx])
        continue;
      // 얼음이면
      if (a[ny][nx] > 0)
      {
        isMeltIce = true;
        Visit[ny][nx] = 1;
        // 맞닿아 있는 얼음 녹이기
        a[ny][nx]--;

        // 다 녹았으면 큐에 넣기.
        if (a[ny][nx] == 0)
        {
          water.push({ny, nx});
        }
        continue;
      }

      // 아직 안간 물은 nowwater에 넣기
      if (!Visit[ny][nx] && a[ny][nx] == 0)
      {
        nowwater.push({ny, nx});
        Visit[ny][nx] = 1;
      }
    }
    // 얼음을 녹엿으면 다시 큐에 넣기
    if (isMeltIce)
    {
      water.push({y, x});
    }
  }
  // 2. 4방향 돌면서 a[i][j] 가 모두 0이면 water에 안넣기. 하나라도 있으면 water에 다시 넣기
  // 3. 4방향으로 돌면서 a[i][j] >= 1 이면 -1 해주기. (최소 0)
  // 4. 뺐는데 0이면 water에 넣기
}

int main()
{
  cin >> n >> m;

  For(i, n)
  {
    For(j, m)
    {
      cin >> a[i][j];
      if (a[i][j] == 0)
        water.push({i, j});
    }
  }

  int cnt = 0, ret = 0;
  while (isIce())
  {
    bfs();
    cnt++;
    if (CheckIce())
    {
      ret++;
      break;
    }
  }

  if (ret == 0)
    cout << 0;
  else
    cout << cnt;
}