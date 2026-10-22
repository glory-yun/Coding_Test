#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int from, to;
int degree[100005], visit[100005];
vector<int> v[100005];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        v[from].push_back(to);
        degree[to]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    
    for(int i=1; i <= n; i++){
        if(degree[i] == 0) 
            pq.push(i);
    }

    int cnt = 0;
    vector<int> ret;
    while(pq.size()){

        cnt++;
        int now = pq.top(); pq.pop();

        ret.push_back(now);

        for(int next : v[now]){
            if(--degree[next] == 0) pq.push(next);
        }
    }
     
    if(cnt != n) cout << -1;
    else{
        for(auto e : ret) cout << e << " ";
    }
    

    return 0;
}