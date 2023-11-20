#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

unsigned long long check(unsigned long long time, unsigned long long n, vector<int> a)
{
	unsigned long long people = 0;
	for (int i = 0; i < n; i++)
	{
		people = people + time / a[i];
	}
	return people;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long n, m, temp, left, right, mid, max = 0;
	vector<int> a;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
		if (temp > max)
			max = temp;
	}
	sort(a.begin(), a.end());

	left = 0;
	right = max * m;
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (check(mid, n, a) < m) // 크면 시간을 늘리고 같으면 시간을 줄인다
			left = mid; // 늘리기
		else
			right = mid;  // 줄이기
	}
	cout << right;
}