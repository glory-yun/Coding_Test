#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	while (1)
	{
		getline(cin, str);

		if (str == ".") break;

		stack<char> stk;
		for (auto ch : str)
		{
			if(ch == '(' || ch == '[') stk.push(ch);
			else if (ch == ')') {
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else {
					stk.push(ch);
				}
			}
			else if (ch == ']') {
				if (!stk.empty() && stk.top() == '[') stk.pop();
				else {
					stk.push(ch);
				}
			}
		}
		if (stk.empty()) {
			cout << "yes" << endl;
			continue;
		}
		else {
			cout << "no" << endl;
			continue;
		}
	}
}