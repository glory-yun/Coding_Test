#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
void START()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

int n, m, ret = 0;

int main()
{
    START();

    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] > m)
                break;
            if (v[i] + v[j] == m)
                ret++;
        }
    }
    cout << ret;
}