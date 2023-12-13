#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[1000];
	int str, n, d, e, x = 0, y = 0, ans = 0;
	cin >> n;
	for (int i = 123; i <= 987; i++)
		arr[i] = 1;
	for (int j = 0; j < n; j++)
	{
		cin >> str >> d >> e;
		for (int i = 123; i <= 987; i++)
		{
			if (arr[i] == 1 && (i % 10 == 0 || (i / 10) % 10 == 0 || (i / 100) % 10 == 0 ||
				i % 10 == (i / 10) % 10 || (i / 10) % 10 == (i / 100) % 10 || i % 10 == (i / 100) % 10))
				arr[i] = 0;
			x = 0;
			y = 0;
			if (arr[i] == 1)
			{
				if (str % 10 == i % 10)
					x++;
				else
				{
					if (str % 10 == (i / 10) % 10 || str % 10 == (i / 100) % 10)
						y++;
				}
				if ((str / 10) % 10 == (i / 10) % 10)
					x++;
				else
				{
					if ((str / 10) % 10 == i % 10 || (str / 10) % 10 == (i / 100) % 10)
						y++;
				}
				if ((str / 100) % 10 == (i / 100) % 10)
					x++;
				else
				{
					if ((str / 100) % 10 == i % 10 || (str / 100) % 10 == (i / 10) % 10)
						y++;
				}
				if (x != d || y != e)
					arr[i] = 0;
			}
		}
	}
	for (int i = 123; i <= 987; i++)
	{
		if (arr[i] == 1)
		{
			ans++;
		}
	}
	cout << ans;
}