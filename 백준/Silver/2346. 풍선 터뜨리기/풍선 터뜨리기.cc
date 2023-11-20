#include <iostream>
#include <list>
#include <string>
using namespace std;

typedef struct bal{
	int target;
	int index;
} loon;

int main()
{
	int n, i = 1, temp, target;
	list<loon> lst;
	loon none;

	cin >> n;
	while (n > 0)
	{
		cin >> temp;
		none.target = temp;
		none.index = i;
		lst.push_back(none);
		i++;
		n--;
	}
	while (!lst.empty())
	{
		target = lst.front().target;
		cout << lst.front().index << ' ';
		lst.pop_front();
		if (lst.empty())
			break;
		if (target < 0)
		{
			while (target != 0)
			{
				lst.push_front(lst.back());
				lst.pop_back();
				target++;
			}
		}
		else
		{
			while (target != 1)
			{
				lst.push_back(lst.front());
				lst.pop_front();
				target--;
			}
		}
	}
}