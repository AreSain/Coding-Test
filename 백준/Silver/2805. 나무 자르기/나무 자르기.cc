#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long check(long cut, long n, vector<int> a)
{
	long wood = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] - cut > 0)
			wood = wood + a[i] - cut;
	}
	return wood;
}

int main()
{
	long n, m, temp, left, right, mid;
	vector<int> a;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());

	left = 0;
	right = a.back();
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (check(mid, n, a) < m)
			right = mid;
		else
			left = mid;
	}
	cout << left;
}