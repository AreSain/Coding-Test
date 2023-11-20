#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int arr[1024];

void call(int n, int k)
{
	int temp, plus;
	if (k > 9)
	{
		cout << arr[n / 2] << '\n';
	}
	if (k > 8)
	{
		temp = pow(2, 8);
		plus = pow(2, 9);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 7)
	{
		temp = pow(2, 7);
		plus = pow(2, 8);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 6)
	{
		temp = pow(2, 6);
		plus = pow(2, 7);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 5)
	{
		temp = pow(2, 5);
		plus = pow(2, 6);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 4)
	{
		temp = pow(2, 4);
		plus = pow(2, 5);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 3)
	{
		temp = pow(2, 3);
		plus = pow(2, 4);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 2)
	{
		temp = pow(2, 2);
		plus = pow(2, 3);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 1)
	{
		temp = pow(2, 1);
		plus = pow(2, 2);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
		cout << '\n';
	}
	if (k > 0)
	{
		temp = pow(2, 0);
		plus = pow(2, 1);
		while (temp - 1 <= n)
		{
			cout << arr[temp - 1] << ' ';
			temp += plus;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, temp, ans = 1, num, p;
	cin >> k;
	p = k;
	while (k > 0)
	{
		ans = ans * 2;
		k--;
	}
	num = ans;
	for (int i = 0; i + 1 < ans; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}
	call(num - 2, p);
}