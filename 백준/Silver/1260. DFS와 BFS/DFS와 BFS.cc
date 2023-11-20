#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector< vector<int> >& arr, vector<int>& visit, int start)
{
	int y;

	visit[start] = 1;
	cout << start << ' ';
	for (int i = 1; i <= arr[start].size(); i++)
	{
		if (arr[start][i] == 1)
		{
			y = i;
			if (!visit[y])
				dfs(arr, visit, y);
		}
	}
}

void bfs(vector< vector<int> >& arr, vector<int>& visit, int start)
{
	int temp;
	queue<int> q;

	q.push(start);
	visit[start] = 1;
	while (!q.empty())
	{
		temp = q.front();
		cout << temp << ' ';
		for (int i = 1; i <= arr[temp].size(); i++)
		{
			if (arr[temp][i] == 1)
			{
				if (!visit[i])
				{
					q.push(i);
					visit[i] = 1;
				} 
			}
		}
		q.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
 
	int n, m, start, x , y;
	cin >> n >> m >> start;
	vector< vector<int> > arr(n + 1, vector<int>(n + 1, 0));
	vector<int> visit(n + 1, 0);
	vector<int> visited(n + 1, 0);
	for (int j = 0; j < m; j++)
	{ 
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	} 
	dfs(arr, visit, start);
	cout << '\n';
	bfs(arr, visited, start);
}