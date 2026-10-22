#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
char signs[1000];

int degree[1000], degree_max[1000];
vector<int> v[1000], v_max[1000];

priority_queue<int, vector<int>, greater<int>> pq_min;
priority_queue<int, vector<int>, greater<int>> pq_max;

int ret_min[1000], ret_max[1000];

int main() {
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        cin >> signs[i];
    }

    // 그래프 생성
    for(int i = 0; i < n - 1; i++) {
        int idx = i + 1;
        int next = i + 2;

        if(signs[i] == '<') {
            v[idx].push_back(next);
            degree[next]++;

            v_max[next].push_back(idx);
            degree_max[idx]++;
        }
        else {
            v[next].push_back(idx);
            degree[idx]++;

            v_max[idx].push_back(next);
            degree_max[next]++;
        }
    }

    // 진입 차수가 0인 정점 추가
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0)
            pq_min.push(i);

        if(degree_max[i] == 0)
            pq_max.push(i);
    }

    // 사전순 최소 수열
    int num = 1;

    while(!pq_min.empty()) {
        int now = pq_min.top();
        pq_min.pop();

        ret_min[now] = num++;

        for(int next : v[now]) {
            if(--degree[next] == 0) {
                pq_min.push(next);
            }
        }
    }

    // 사전순 최대 수열
    num = n;

    while(!pq_max.empty()) {
        int now = pq_max.top();
        pq_max.pop();

        ret_max[now] = num--;

        for(int next : v_max[now]) {
            if(--degree_max[next] == 0) {
                pq_max.push(next);
            }
        }
    }

    // 사전순 최소 출력
    for(int i = 1; i <= n; i++) {
        if(ret_min[i] < 10) cout << "00";
        else if(ret_min[i] < 100) cout << "0";

        cout << ret_min[i];
    }
    cout << '\n';

    // 사전순 최대 출력
    for(int i = 1; i <= n; i++) {
        if(ret_max[i] < 10) cout << "00";
        else if(ret_max[i] < 100) cout << "0";

        cout << ret_max[i];
    }
    cout << '\n';

    return 0;
}