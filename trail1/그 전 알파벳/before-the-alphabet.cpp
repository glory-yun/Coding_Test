#include <iostream>
using namespace std;

int main() {
    // Please write your code here.

    char ch; cin >> ch;

    if(ch  == 'a') cout << 'z';
    else cout << (char)(ch -1);

    return 0;
}