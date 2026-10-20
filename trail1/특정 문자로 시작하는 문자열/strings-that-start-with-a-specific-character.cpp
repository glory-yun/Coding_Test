#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
 
    int n; 
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    char ch; 
    cin >> ch;

    int cnt = 0;
    double len = 0;

    for (const auto& s : v) {
        if (!s.empty() && s[0] == ch) {
            cnt++;
            len += s.size();
        }
    }

    cout << fixed << setprecision(2);

    if (cnt == 0) {
        cout << 0 << " " << 0.00 << "\n";
    } else {
        cout << cnt << " " << (len / cnt) << "\n";
    }

    return 0;
}