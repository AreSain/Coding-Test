#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp, left, right, mid;
	vector<int> ans;
	set<int> a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.insert(temp);
	}
	cin >> m;
	ans.assign(a.begin(), a.end());
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		left = 0;
		right = ans.size();
		while (left + 1 < right)
		{
			mid = (left + right) / 2;
			if (ans[mid] < temp)
				left = mid;
			else if (ans[mid] > temp)
				right = mid;
			else
				break;
		}
		if (ans[left] == temp || ans[mid] == temp)
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
	}
}