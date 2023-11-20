#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dfs(vector< vector<int> >& arr, vector< vector<int> >& visit, int y, int x, int n)
{
	if (y < 0 || y >= n || x < 0 || x >= n || visit[y][x] == 1 || arr[y][x] == 0)
		return 0;

	visit[y][x] = 1;

	return 1 + dfs(arr, visit, y - 1, x, n) + dfs(arr, visit, y + 1, x, n)
		+ dfs(arr, visit, y, x - 1, n) + dfs(arr, visit, y, x + 1, n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, house;
	string temp;
	cin >> n;
	vector< vector<int> > arr(n + 1, vector<int>(n + 1, 0));
	vector< vector<int> > visit(n + 1, vector<int>(n + 1, 0));
	vector<int> ans;
	for (int j = 0; j < n; j++)
	{
		cin >> temp;
		for (int i = 0; i < n; i++)
		{
			arr[j][i] = temp[i] - '0';
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[j][i] == 1 && !visit[j][i])
			{
				house = dfs(arr, visit, j, i, n);
				ans.push_back(house);
			}
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}