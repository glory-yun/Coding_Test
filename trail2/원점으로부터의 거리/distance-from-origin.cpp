#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;

struct node{

    int y,x,idx;

    node(int y,int x,int idx){
        this->x = x;
        this->y = y;
        this->idx = idx;
    }
};

bool cmp(node p1, node p2){

    if(abs(p1.x)+abs(p1.y) == abs(p2.x) + abs(p2.y)){

        return p1.idx <p2.idx;
    }

    return abs(p1.x)+abs(p1.y) < abs(p2.x) + abs(p2.y);
}

int main() {
    cin >> N;

    vector<node> v;

    for (int i = 1; i <= N; i++) {
        int a, b; cin >>a >> b;
        v.push_back(node(a,b,i));
    }

    // Please write your code here.
    sort(v.begin(), v.end(), cmp);

    for(auto ret : v){
        cout << ret.idx << endl;
    }

    return 0;
}
