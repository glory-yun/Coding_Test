#include <bits/stdc++.h>
using namespace std;

void START() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

string normalize(string s) {
    // 앞자리 0 제거
    int i = 0;
    while (i < (int)s.size() && s[i] == '0') i++;
    if (i == (int)s.size()) return "0";   // 전부 0이었음
    return s.substr(i);
}

int main() {
    START();

    long long n;
    cin >> n;

    vector<string> nums;
    string line, cur;

    while (n--) {
        cin >> line;
        cur.clear();

        for (char ch : line) {
            // isdigit은 unsigned char 캐스팅이 안전합니다.
            if (isdigit(static_cast<unsigned char>(ch))) {
                cur += ch;
            } else {
                if (!cur.empty()) {
                    nums.push_back(normalize(cur));
                    cur.clear();
                }
            }
        }
        if (!cur.empty()) {
            nums.push_back(normalize(cur));
            cur.clear();
        }
    }

    // 길이 우선, 길이 같으면 사전순 비교
    sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for (const auto& s : nums) {
        cout << s << '\n';
    }
    return 0;
}
