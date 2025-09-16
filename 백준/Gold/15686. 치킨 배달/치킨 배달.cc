#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 1; i <= n; i++)

void START()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
typedef long long ll;

ll n, m, k;

int result = INT_MAX;

int a[55][55];
int Visit[55][55];

vector<pair<int, int>> chicken, house;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 치킨집 여러 치킨집중 m개 고르기 - 재귀
// 각 집마다 m개의 치킨집 중에서 가까운 곳의 거리를 계산 - bfs
// 각 집마다 최솟 값을 구해서 더하기
// 이걸 xCm 번 반복해서 찐 최소 거리 구하기

// 각 집, 각 치킨집 마다 최소 거리 구하기

void chickenLoad(vector<pair<int, int>> pickChicken)
{
    // 집의 위치, 치킨집의 위치 구하기

    int RET = 0;
    // 여기 다시 하기 (집마다 최솟값 구하기)
    for (auto h : house)
    {
        int minlength = INT_MAX;

        for (auto c : pickChicken)
        {
            int ret = abs(h.first - c.first) + abs(h.second - c.second);

            minlength = min(minlength, ret);
        }
        RET += minlength;
    }

    result = min(result, RET);
}

void combi(vector<pair<int, int>> pickChicken, int start)
{

    if (pickChicken.size() == m)
    {
        chickenLoad(pickChicken);
    }

    for (int i = start + 1; i < chicken.size(); i++)
    {
        pickChicken.push_back(chicken[i]);
        combi(pickChicken, i);
        pickChicken.pop_back();
    }
    return;
}

// void go(int count)
// {
//     // 치킨집 n개를 뽑았을 떄 실행
//     if (count == m)
//     {
//         chickenLoad();
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             // 치킨집 고르기
//             if (a[i][j] == 2)
//             {
//                 a[i][j] = 3;
//                 go(count + 1);
//                 a[i][j] = 2;
//             }
//         }
//     }
//     return;
// }

int main()
{
    START();
    cin >> n >> m;

    FOR(i, n)
    {
        FOR(j, n)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
                chicken.push_back({i, j});
            if (a[i][j] == 1)
                house.push_back({i, j});
        }
    }

    vector<pair<int, int>> pickChicken;

    combi(pickChicken, -1);

    cout << result;
}
