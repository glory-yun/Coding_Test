#include <iostream>
#include <string>

using namespace std;

string A, B;

int main() {
    cin >> A;
    cin >> B;

    while(A.find(B) != string::npos){
        A.erase(A.find(B), B.size());
    }

    cout << A;
    return 0;
}
