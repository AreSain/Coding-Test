#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector< vector<int> >& arr, vector<int>& visit, int bug, int *ans)
{
	int y;

	visit[bug] = 1;
	(*ans)++;
	for (int i = 1; i < arr[bug].size(); i++)
	{
		if (arr[bug][i] == 1)
		{
			y = i;
			if (!visit[y])
				dfs(arr, visit, y, ans);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, y, ans;
	cin >> n >> m;
	ans = 0;
	vector< vector<int> > arr(n + 1, vector<int>(n + 1, 0));
	vector<int> visit(n + 1, 0);
	for (int j = 0; j < m; j++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(arr, visit, 1, &ans);
	cout << ans - 1;
}