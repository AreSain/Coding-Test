#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 3;
	cin >> n;

	int all = 3;
	int mid = 3;

	while (all < n)
	{
		all = all + all + ++mid;
	}

	while (1)
	{
		int left = (all - mid) / 2;

		if (n <= left) // left
		{
			all = left;
			mid--;
		}
		else if (n > left + mid) // right
		{
			n = n - left - mid;
			mid--;
			all = left;
		}
		else // mid
		{
			n = n - left;
			break;
		}
	}
	if (n == 1)
		cout << "m";
	else
		cout << "o";
}


