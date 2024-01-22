#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[501][501];
int dp[501][501];
int n, m;
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int check(int y, int x)
{
	if (y == n && x == m)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cy >= 1 && cx >= 1 && cy <= n && cx <= m && map[y][x] > map[cy][cx])
			dp[y][x] += check(cy, cx);
	}
	return dp[y][x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}	
	check(1, 1);
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/
	cout << dp[1][1];
}