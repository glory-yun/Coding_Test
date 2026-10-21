#include <iostream>

using namespace std;

int n, m;
int query[100000][3];

int parent[100005];

int find(int x){
    if(parent[x] == x) return x;

    return x = find(parent[x]);
}

void Union(int a,int b){

    int roota = find(a), rootb = find(b);

    if(roota < rootb) parent[rootb] = roota;
    else parent[rootb] = roota;

}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> query[i][0] >> query[i][1] >> query[i][2];
    }

    // Please write your code here.

    for(int i=1; i<=n;i++) parent[i] = i;

    for(int i=0; i< m;i++){

        if(query[i][0] == 0){
            Union(query[i][1] , query[i][2]);
        }
        else{
            cout << (find(query[i][1]) == find(query[i][2])) << endl;
        }

    }


    return 0;
}