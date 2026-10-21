#include <iostream>

using namespace std;

int n, m, k;
int from[100000], to[100000];
int path[100000];
int parent[100005];

int find(int x){
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);

}

void Union(int a, int b){

    int roota = find(a), rootb = find(b);

    if(roota < rootb) parent[rootb] = roota;
    else parent[roota] = rootb;
}

int main() {
    cin >> n >> m >> k;
    for(int i=1 ; i<=n;i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> path[i];
    }

    // Please write your code here.
     for (int i = 0; i < m; i++) {
        Union(from[i] , to[i]);
    }

    bool flag = true;
    for (int i = 0; i < k-1; i++) {
        if(find(path[i]) != find(path[i+1])){
            flag = false;
            break;
        }    
    }

    if(flag) cout << 1;
    else cout << 0;
    return 0;
}