#include <iostream>

using namespace std;

int n, m;
int a[100000], b[100000];
int parent[100005];

int find(int x) {
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void Union(int a,int b){

    int roota = find(a), rootb = find(b);

    if(roota < rootb) parent[roota] = rootb;
    else parent[rootb] = roota; 
}

int main() {
    cin >> n >> m;

    for(int i=1; i<=n;i++)parent[i]=i;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.

    int cnt = n;
    for (int k = 0; k < m; k++) {
        
        int start = find(a[k]), end = b[k];

        while(start < end){

            Union(start, start+1);
            cnt--;

            start = find(start);
        }


        cout << cnt << endl;
    }

    return 0;
}