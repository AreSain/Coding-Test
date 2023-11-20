#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	int n, i = 0;
	char temp;
	string str;
	list<char> left;
	list<char> right;

	cin >> n;
	while (n > 0)
	{
		cin >> str;
		i = 0;
		while (i < str.size())
		{
			if (str[i] == '<')
			{
				if (!left.empty())
				{
					right.push_front(left.back());
					left.pop_back();
				}
			}
			else if (str[i] == '>')
			{
				if (!right.empty())
				{
					left.push_back(right.front());
					right.pop_front();
				}
			}
			else if (str[i] == '-')
			{
				if (!left.empty())
					left.pop_back();
			}
			else
				left.push_back(str[i]);
			i++;
		}
		while (!left.empty())
		{
			cout << left.front();
			left.pop_front();
		}
		while (!right.empty())
		{
			cout << right.front();
			right.pop_front();
		}
		cout << '\n';
		n--;
	}
}