#include <iostream>
#include <string>

using namespace std;

string input_str;
string target_str;

int main() {
    cin >> input_str;
    cin >> target_str;

    // Please write your code here.
    int idx = input_str.find(target_str);

    cout << idx;
    return 0;
}
