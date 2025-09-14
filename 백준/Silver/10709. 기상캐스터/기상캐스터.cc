#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

void START()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
typedef long long ll;

ll n, m;

int h, k;

char a[105][105];
int main()
{
    cin >> h >> k;

    FOR(i, h)
    {
        FOR(j, k)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        int cloud = -1;
        for (int j = 0; j < k; j++)
        {
            if (a[i][j] == 'c')
            {
                cloud = 0;
            }
            else if (a[i][j] != 'c')
            {
                if (cloud != -1)
                    cloud++;
            }

            cout << cloud << " ";
        }
        cout << endl;
    }
}