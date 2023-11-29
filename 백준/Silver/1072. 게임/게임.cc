#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long x, y;
	long long z, left = 0, right = 1000000000, mid;

	cin >> x >> y;

	z = (100 * y) / x;
	if (z >= 99)
	{
		cout << "-1" << '\n';
		return 0;
	}
	while (left <= right)
	{
		mid = (left + right) / 2;
		int chz = (100 * (y + mid)) / (x + mid);
		if (chz > z)
			right = mid - 1;
		else
		{
			left = mid + 1;
		}
	}
	cout << left << '\n';
}
