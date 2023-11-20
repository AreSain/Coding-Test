#include <iostream>
using namespace std;

int main()
{
	int n, k, temp, ans = 0, flag = 0;
	int str[10000];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		str[i] = temp;
	}
	while (ans != k && n != 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (str[i] > str[i + 1])
			{
				temp = str[i + 1];
				str[i + 1] = str[i];
				str[i] = temp;
				ans++;
				if (ans == k)
				{
					cout << str[i] << ' ' << str[i + 1];
					flag = -1;
				}
			}
		}
		n--;
	}
	if (flag == 0)
		cout << "-1";
}