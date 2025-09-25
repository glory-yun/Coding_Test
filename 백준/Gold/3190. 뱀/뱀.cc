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

int a[105][105];

vector<pair<int, int>> apple;
queue<pair<int, char>> role;
int p, q, l, x;
char c;

deque<pair<int, int>> snake;

void Input()
{
  cin >> n >> k;
  while (k--)
  {
    cin >> p >> q;
    apple.push_back({p, q});
    a[p][q] = 2;
  }
  cin >> l;
  while (l--)
  {
    cin >> x >> c;
    role.push({x, c});
  }
}
// 1~n 까지 움직이기 가능
// 처음 방향은 오른쪽, 1,1에서 시작함

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
  Input();
  int cnt = 0;
  snake.push_back({1, 1}); // 1,1에서 시작

  int dir_idx = 1;
  // game start
  while (true)
  {
    ++cnt;

    int y, x;
    tie(y, x) = snake.front();

    // 다음 칸
    int ny = y + dir[dir_idx].first, nx = x + dir[dir_idx].second;

    // 벽에 부딪치면
    if (ny <= 0 || nx <= 0 || ny > n || nx > n)
      break;

    // 머리에 부딪치면
    pair<int, int> find_pair = {ny, nx};
    if (find(snake.begin(), snake.end(), find_pair) != snake.end())
      break;

    // 사과가 없다면
    if (a[ny][nx] != 2)
    {
      snake.push_front({ny, nx});
      snake.pop_back();
    }
    // 사과가 있다면
    else
    {
      snake.push_front({ny, nx});
      a[ny][nx] = 0;
    }

    // 뱀이 회전
    if (!role.empty() && cnt == role.front().first)
    {
      // 왼쪽으로 90도 회전
      if (role.front().second == 'L')
      {
        dir_idx = dir_idx - 1 == -1 ? 3 : dir_idx - 1;
      }
      // 오른쪽으로 90도 회전
      else
      {
        dir_idx = dir_idx + 1 == 4 ? 0 : dir_idx + 1;
      }

      role.pop();
    }
  }

  cout << cnt;
}