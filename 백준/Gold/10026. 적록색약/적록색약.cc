#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, ans = 0, color, eye;
vector< vector<char> > arr;
vector< vector<int> > visit;

void dfs(int y, int x, int color, int eye)
{
	if (y < 0 || y >= n || x < 0 || x >= n || visit[y][x])
		return;
	if (eye && (color == 'R' || color == 'G'))
	{
		if (arr[y][x] != 'R' && arr[y][x] != 'G')
			return;
	}
	else if (arr[y][x] != color)
		return;
	visit[y][x] = color;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		dfs(ny, nx, color, eye);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr.resize(n, vector<char>(n));
	visit.resize(n, vector<int>(n, 0));

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			char temp;
			cin >> temp;
			arr[j][i] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == 0)
			{
				dfs(i, j, arr[i][j], 0);
				ans++;
			}
		}
	}
	cout << ans << ' ';

	ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j] && (arr[i][j] == 'R' || arr[i][j] == 'G'))
			{
				dfs(i, j, 'R', 1);
				ans++;
			}
			else if (!visit[i][j] && arr[i][j] == 'B')
			{
				dfs(i, j, 'B', 1);
				ans++;
			}
		}
	}
	cout << ans;
}