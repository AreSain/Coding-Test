#include <istream>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, num;
	string str;
	queue<int> stack, ans;

	cin >> n;
	cin.ignore();
	while (n > 0)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			stack.push(num);
		}
		else if (str == "front")
			if (!stack.empty())
				ans.push(stack.front());
			else
				ans.push(-1);
		else if (str == "size")
			ans.push(stack.size());
		else if (str == "pop")
		{
			if (!stack.empty())
			{
				ans.push(stack.front());
				stack.pop();
			}
			else
				ans.push(-1);
		}
		else if (str == "back")
		{
			if (!stack.empty())
				ans.push(stack.back());
			else
				ans.push(-1);
		}
		else if (str == "empty")
			ans.push(stack.empty());
		n--;
	}
	while (!ans.empty())
	{
		cout << ans.front() << '\n';
		ans.pop();
	}
}