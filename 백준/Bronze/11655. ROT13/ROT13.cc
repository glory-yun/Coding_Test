#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string str; 
    getline(cin, str);
    string ret = "";


    for (char ch : str)
    {   
        if(!isalpha(ch)){
            ret += ch;
            continue;
        }
        int c = ch - 0;

        if ((97 <= c && c + 13 <= 122) || (65 <= c && c + 13 <= 90))
        {
            ret += (char)(c+13);
        }
        else if ((97 <= c && c + 13 > 122) || (65 <= c && c + 13 > 90))
        {
            ret += (char)(c-13);
        }
        
    }

    cout << ret;

} // 65 90 97 122