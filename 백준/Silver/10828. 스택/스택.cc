#include <istream>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	int n, num;
	string str, arr;
	stack<int> stack;

	cin >> n;
	cin.ignore();
	while (n > 0)
	{
		getline(cin, arr);
		stringstream ss(arr);
		ss >> str;
		if (str == "push")
		{
			ss >> num;
			stack.push(num);
		}
		if (str == "top")
			if (!stack.empty())
				cout << stack.top() << endl;
			else
				cout << "-1" << endl;
		if (str == "size")
			cout << stack.size() << endl;
		if (str == "pop")
		{
			if (!stack.empty())
			{
				cout << stack.top() << endl;
				stack.pop();
			}
			else
				cout <<	"-1" << endl;
		}
		if (str == "empty")
			cout << static_cast<int>(stack.empty()) << endl;
		n--;
	}
}