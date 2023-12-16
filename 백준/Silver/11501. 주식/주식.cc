#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long t, n;
	
	cin >> t;
	for (long long i = 0; i < t; i++)
	{
		vector<long long>ans;
		cin >> n;
		for (long long j = 0, temp; j < n; j++)
		{
			cin >> temp;
			ans.push_back(temp);
		}
		long long sum = 0;
		long long max = ans[ans.size() - 1];
		for (long long j = ans.size() - 1; j >= 0; j--)
		{
			if (ans[j] > max)
				max = ans[j];
			else
				sum += max - ans[j];
		}
		cout << sum << '\n';
	}
}