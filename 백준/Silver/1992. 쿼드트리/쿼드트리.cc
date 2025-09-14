#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

void START() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
typedef long long ll;

int a[65][65];
int now;

void dfs(int y, int x, int len)
{
    if (len == 1) {
        cout << a[y][x];
        return;
    }

    // 전체 검사
    bool other = false;
    now = a[y][x];
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (a[i][j] != now) {
                other = true;
            }
        }
    }
    if (!other) {
        cout << now;
        return;
    }

    cout << "(";

    // 1사분면: (y, x) ~ (y+len/2, x+len/2)
    other = false;
    now = a[y][x];
    for (int i = y; i < y + len / 2; i++) {
        for (int j = x; j < x + len / 2; j++) {
            if (a[i][j] != now) {
                other = true;
            }
        }
    }
    if (other) dfs(y, x, len / 2);
    else cout << now;

    // 2사분면: (y, x+len/2) ~ (y+len/2, x+len)
    other = false;
    now = a[y][x + len / 2];
    for (int i = y; i < y + len / 2; i++) {
        for (int j = x + len / 2; j < x + len; j++) { // ✅ 상한 수정
            if (a[i][j] != now) {
                other = true;
            }
        }
    }
    if (other) dfs(y, x + len / 2, len / 2);
    else cout << now;

    // 3사분면: (y+len/2, x) ~ (y+len, x+len/2)
    other = false;
    now = a[y + len / 2][x];
    for (int i = y + len / 2; i < y + len; i++) {      // ✅ 상한 수정
        for (int j = x; j < x + len / 2; j++) {
            if (a[i][j] != now) {
                other = true;
            }
        }
    }
    if (other) dfs(y + len / 2, x, len / 2);
    else cout << now;

    // 4사분면: (y+len/2, x+len/2) ~ (y+len, x+len)
    other = false;
    now = a[y + len / 2][x + len / 2];
    for (int i = y + len / 2; i < y + len; i++) {      // ✅ 상한 수정
        for (int j = x + len / 2; j < x + len; j++) {  // ✅ 상한 수정
            if (a[i][j] != now) {
                other = true;
            }
        }
    }
    if (other) dfs(y + len / 2, x + len / 2, len / 2);
    else cout << now;

    cout << ")";
}

int main()
{
    START();

    int n;
    cin >> n;
    FOR(i, n) {
        string s; cin >> s;
        FOR(j, n) a[i][j] = s[j] - '0';
    }
    dfs(0, 0, n);
    return 0;
}
