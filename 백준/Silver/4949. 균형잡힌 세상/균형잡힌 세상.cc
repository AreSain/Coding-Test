#include <istream>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i = 0, flag;
	string str;
	stack<char> stack;
	while (1)
	{
		getline(cin, str);
		if (str[0] == '.')
			break;
		i = 0;
		flag = 1;
		while (str[i] != '\0')
		{
			if (str[i] == '(')
				stack.push('(');
			else if (str[i] == '[')
				stack.push('[');
			else if (str[i] == ')')
			{
				if (stack.empty() || stack.top() != '(')
				{
					flag = -1;
					break;
				}
				stack.pop();
			}
			else if (str[i] == ']')
			{
				if (stack.empty() || stack.top() != '[')
				{
					flag = -1;
					break;
				}
				stack.pop();
			}
			i++;
		}
		if (!stack.empty())
			flag = -1;
		while (!stack.empty())
			stack.pop();
		if (flag == 1)
		{
			cout << "yes\n";
		}
		else
			cout << "no\n";
	}
}