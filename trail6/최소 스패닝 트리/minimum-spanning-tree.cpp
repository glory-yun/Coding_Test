#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int from[100000], to[100000], weight[100000];
int parent[100005];

struct edge{
    int from, to, w;

    edge(int from, int to, int w){
        this->from = from;
        this->to = to;
        this->w = w;
    }

    bool operator< (edge o) const {
        return w < o.w;
    }
};

int find(int x){

    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void Union(int a,int b){

    int A = find(a), B = find(b);

    if(A <B) parent[B] = A;
    else parent[A] = B;
}


int main() {
    cin >> n >> m;

    vector<edge> edges;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];

        edges.push_back(edge(from[i], to[i], weight[i]));
    }

    // Please write your code here.
    
    for(int i=1; i<=n;i++) parent[i] = i;

    sort(edges.begin(), edges.end());
    int cnt =0 , sum = 0;

    for(auto ed : edges){

        if(find(ed.from) == find(ed.to)) continue;

        Union(ed.from,ed.to);
        
        sum += ed.w;

        if(cnt++ == n) break;


    }
    cout << sum;
    return 0;
}