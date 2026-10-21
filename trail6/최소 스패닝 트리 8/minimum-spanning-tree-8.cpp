#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int from, to, weight;

struct edge{

    int to ,w;

    edge(int to,int w){
        this->to = to;
        this->w = w;
    }

    bool operator < (edge o) const{
        return w > o.w;
    }
};

int main() {
    cin >> n >> m;

    vector<edge> edges[n+1];

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        edges[from].push_back(edge{to,weight});
        edges[to].push_back(edge{from,weight});
    }

    // Please write your code here.
    priority_queue<edge> pq;
    int visit[n+1];
    fill(visit, visit + n+1 , 0);
    pq.push({1,0});

    int cnt =0, sum = 0;
    while(pq.size()) {
        auto now = pq.top(); pq.pop();

        if(visit[now.to]) continue;


        visit[now.to] = true;
        sum += now.w;

        if(++cnt == n) break;

        for(auto next : edges[now.to]){
            if(!visit[next.to]) pq.push(next);
        }

    }

    cout << sum;
    return 0;
}