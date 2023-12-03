#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, melttime = 0, cheese = 0;
int arr[101][101];
int visit[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void abc(queue<pair<int, int>> melting)
{
	while (!melting.empty())
	{
		pair<int, int> p = melting.front();
		melting.pop();
		arr[p.first][p.second] = 3;
		for (int k = 0; k < 4; k++)
		{
			int cy = p.first + dy[k];
			int cx = p.second + dx[k];
			if (cx >= 0 && cy >= 0 && cx < m && cy < n && arr[cy][cx] == 0)
			{
				arr[cy][cx] = 3;
				melting.push({ cy, cx });
			}
		}
	}
}

void closeair()
{
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cy >= 0 && cx >= 0 && cy < n && cx < m && visit[cy][cx] == 0 && arr[cy][cx] == 0)
			{
				visit[cy][cx] = 1;
				arr[cy][cx] = 3;
				q.push({ cy, cx });
			}
		}
	}
}

void check()
{
	closeair();
	while (1)
	{
		if (cheese == 0)
			break;
		queue<pair<int, int>> melting;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && cheese > 0)
				{
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int cx = j + dx[k];
						int cy = i + dy[k];
						if (cx >= 0 && cy >= 0 && cx < m && cy < n && arr[cy][cx] == 3)
							cnt++;
					}
					if (cnt >= 2)
					{
						cheese--;
						melting.push({ i, j });
					}
				}
			}
		}
		melttime++;
		if (cheese == 0)
			break;
		abc(melting);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				cheese++;
		}
	}
	check();
	cout << melttime;
}