#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int a, b;
int degree[100005]; //뒤에 연결된 간선의 수

int main() {
    cin >> n >> m;

    vector<int> v[n+1];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        v[a].push_back(b);
        degree[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n;i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    while(q.size()){

        int now = q.front(); q.pop();

        cout << now << " ";
        for(auto next : v[now]){
            degree[next]--;

            if(degree[next] == 0) q.push(next);
        }

    }

    return 0;
}