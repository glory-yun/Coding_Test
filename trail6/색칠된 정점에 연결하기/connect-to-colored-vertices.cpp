#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
int from, to, weight;
int colored[100000];

struct edge{

    int to, w;
    edge(int to, int w){
        this->to = to;
        this->w = w;
    }

    bool operator < (edge o ) const{
        return  w > o.w;
    }
};

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> colored[i];
    }


    vector<edge> edges[n+1];
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;

        edges[from].push_back(edge(to,weight));
        edges[to].push_back(edge(from,weight));
    }

    priority_queue<edge> pq;
     for (int i = 0; i < k; i++) {
        pq.push(edge(colored[i],0));
    }

    int visit[n+1];
    fill(visit, visit+n+1, 0);


    int sum=0,cnt=0;
    while(pq.size()){

        edge now = pq.top(); pq.pop();

        if(visit[now.to]) continue;

        visit[now.to] = true;
        sum += now.w;

        if(++cnt == n) break;

        for(auto next : edges[now.to]){
            if(!visit[next.to]){
                pq.push(next);
            }
        }
    }


    cout << sum;

    return 0;
}