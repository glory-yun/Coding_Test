#include <iostream>

using namespace std;
typedef long long ll;

ll mod(ll a, ll b, ll c)
{
    if(b == 1) return a%c;
    
    ll ret = mod(a,b/2,c);
    
    if(b%2==1){
        
        return (ret * ((ret * (a%c))%c) )%c;
    }
    
    return (ret * ret) % c;
}


int main()
{
    ll a,b,c;
    
    cin >> a >> b >> c;
    
    cout << mod(a,b,c);
    
}
