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
int n;

int a[25][25];
int visit[25][25]; // Visit -> visit 소문자로 변경 (C++ 키워드와 혼동 방지)

int eat_fish = 0;
int shark_size = 2;
int shark_y, shark_x;
int total_time = 0;

// findmin 함수가 bfs의 결과를 바탕으로 올바른 물고기를 찾고,
// 찾았다면 true와 함께 이동 시간을 반환하고,
// 못 찾았다면 false를 반환하도록 구조 변경
bool find_and_eat_fish(int &move_time)
{
    int min_dist = INT_MAX;

    // 1. 먹을 수 있는 물고기까지의 최단 거리를 먼저 찾는다.
    For(i, n)
    {
        For(j, n)
        {
            // 먹을 수 있는 물고기이고, 도달도 가능한 경우
            if (a[i][j] > 0 && a[i][j] < shark_size && visit[i][j] != 0)
            {
                min_dist = min(min_dist, visit[i][j]);
            }
        }
    }

    // 먹을 수 있는 물고기가 하나도 없는 경우
    if (min_dist == INT_MAX)
    {
        return false;
    }

    int target_y = -1, target_x = -1;

    // 2. 최단 거리를 가진 물고기들 중에서 우선순위가 가장 높은 것을 찾는다.
    // (가장 위 -> 가장 왼쪽 순서로 찾기 위해 for문을 y=0부터, x=0부터 돌린다)
    For(i, n)
    {
        For(j, n)
        {
            if (visit[i][j] == min_dist && a[i][j] > 0 && a[i][j] < shark_size)
            {
                target_y = i;
                target_x = j;
                // 찾으면 바로 break; -> 가장 위쪽, 왼쪽에 있는 물고기가 확정됨
                goto found;
            }
        }
    }

found:
    // 3. 찾은 물고기를 먹고 상어 상태를 업데이트한다.
    move_time = min_dist - 1; // Visit 배열은 1부터 시작했으므로 실제 거리는 -1
    a[target_y][target_x] = 0;
    shark_y = target_y;
    shark_x = target_x;

    eat_fish++;
    if (eat_fish == shark_size)
    {
        shark_size++;
        eat_fish = 0;
    }

    return true;
}

void bfs()
{
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;

    q.push({shark_y, shark_x});
    visit[shark_y][shark_x] = 1;

    while (!q.empty())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx]) continue;
            if (a[ny][nx] > shark_size) continue; // 큰 물고기는 못 지나감

            visit[ny][nx] = visit[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    For(i, n)
    {
        For(j, n)
        {
            cin >> a[i][j];
            if (a[i][j] == 9)
            {
                shark_y = i;
                shark_x = j;
                a[i][j] = 0;
            }
        }
    }

    while (true)
    {
        // 1. 현재 상어 위치에서 모든 지점까지의 거리를 계산
        bfs();

        int move_time = 0;
        // 2. 계산된 거리를 바탕으로 먹을 물고기를 찾고, 먹음
        if (find_and_eat_fish(move_time))
        {
            // 3. 먹었다면 이동 시간을 총 시간에 더함
            total_time += move_time;
        }
        else
        {
            // 4. 먹을 물고기가 없으면 종료
            break;
        }
    }

    cout << total_time;
    return 0;
}