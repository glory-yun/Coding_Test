#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m1, m2;
int degree[100005];
vector<int> v[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m1 >> m2;

    for(int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        degree[b]++;
    }

    for(int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;

    }

    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        cnt++;

        for(int next : v[now]) {
            if(--degree[next] == 0) {
                q.push(next);
            }
        }
    }

    if(cnt == n) cout << "Yes";
    else cout << "No";

    return 0;
}