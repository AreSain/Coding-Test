#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int m, n, k, temp = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long t, temp;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int tl, tr, left = 0, right = n - 1, max = 2000000001;

	while (left != right)
	{
		temp = v[left] + v[right];
		if (abs(temp) < abs(max))
		{
			max = temp;
			tl = left;
			tr = right;
		}
		if (temp < 0)
			left++;
		else if (temp > 0)
			right--;
		else if (temp == 0)
		{
			cout << v[tl] << " " << v[tr];
			return 0;
		}
	}
	cout << v[tl] << " " << v[tr];
}