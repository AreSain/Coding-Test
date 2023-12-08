#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][21];
int visited[21][21];
int dx[4] = { 1, 0, 1, 1 };
int dy[4] = { -1, 1, 0, 1 };

int bf(int y, int x, int stack, int wayy, int wayx, int flag)
{
	if (wayy != 0 || wayx != 0)
	{
		if (arr[y + wayy][x + wayx] == flag)
		{
			//cout << x << "xy" << y << " " << stack << '\n';
			return (bf(y + wayy, x + wayx, stack + 1, wayy, wayx, flag));
		}
		else if (stack == 5)
			if (arr[y + wayy][x + wayx] != flag)
				return 30;
		else
			return 1;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[y + dy[i]][x + dx[i]] == flag && arr[y - dy[i]][x - dx[i]] != flag)
			{
				int temp = bf(y, x, stack, dy[i], dx[i], flag);
				if (temp == 30)
					return 30;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				visited[i][j] = 1;
		}
	}
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (visited[i][j] == 0 && (arr[i][j] == 1 || arr[i][j] == 2))
				if (bf(i, j, 1, 0, 0, arr[i][j]) == 30)
				{
					cout << arr[i][j] << '\n' << i << ' ' << j;
					return 0;
				}
		}
	}
	cout << '0';
}