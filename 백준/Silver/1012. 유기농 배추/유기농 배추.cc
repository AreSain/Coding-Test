#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, temp = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(vector< vector<int> >&visited, vector< vector<int> >&arr, int y, int x)
{
	if (x < 0 || y < 0 || x >= m || y >= n || arr[y][x] == 0 || visited[y][x] == 1)
		return;
	visited[y][x] = 1;
	temp++;
	for (int i = 0; i < 4; i++)
	{
		bfs(visited, arr, y + dy[i], x + dx[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, ans = 0;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		vector< vector<int> >arr(50, vector<int>(50, 0));
		for (int j = 0; j < k; j++)
		{
			int xtemp, ytemp;
			cin >> xtemp >> ytemp;
			arr[ytemp][xtemp] = 1;
		}
		vector< vector<int> >visited(50, vector<int>(50, 0));
		ans = 0;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				temp = 0;
				if (arr[y][x] == 1 && visited[y][x] == 0)
					bfs(visited, arr, y, x);
				if (temp > 0)
					ans++;
			}
		}
		cout << ans << '\n';
	}
}