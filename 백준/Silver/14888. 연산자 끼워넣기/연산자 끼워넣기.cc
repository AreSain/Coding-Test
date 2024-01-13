#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, min1 = 1000000001, max1 = -1000000001;
int arr[11];

void check(int sum, int i, int p, int m, int mul, int d)
{
	if (i == n - 1)
	{
		if (sum > max1)
			max1 = sum;
		if (sum < min1)
			min1 = sum;
		return;
	}
	if (p != 0)
	{
		check(sum + arr[i + 1], i + 1, p - 1, m, mul, d);
	}
	if (m != 0)
	{
		check(sum - arr[i + 1], i + 1, p, m - 1, mul, d);
	}
	if (mul != 0)
	{
		check(sum * arr[i + 1], i + 1, p, m, mul - 1, d);
	}
	if (d != 0 && arr[i + 1] != 0)
	{
		check(sum / arr[i + 1], i + 1, p, m, mul, d - 1);
	}
	//cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p, m, mul, d;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> p >> m >> mul >> d;
	check(arr[0], 0, p, m, mul, d);
	cout << max1 << '\n' << min1;
}