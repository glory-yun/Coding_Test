#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a(9);
int sum = 0;
//sum - 9c2 = 100

int main()
{
    for(int i=0;i<9;i++) cin >> a[i], sum += a[i];
    

    sort(a.begin(),a.end());

    int p,q;
    for(int i=0;i<9;i++){
        for(int j=i+1; j<9;j++){
            if(sum - a[i] - a[j] == 100){
                p = i;
                q = j;
            }
        }
    }

    

    for(int i=0;i<9;i++){
        if(i == p || i == q) continue;
        cout << a[i] << " ";
    }

}