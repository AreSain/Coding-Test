#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
long long temp, left1, right1, mid1, temp1, temp2, max1 = 0;


long long bfs(long long mid1, vector<vector<pair<int, int>>>arr, long long from, long long to)
{
	vector<int> visit(n + 1, 0);
	queue<int> a;
	a.push(from);
	visit[from] = 1;
	while (!a.empty())
	{
		int now = a.front();
		a.pop();
		if (now == to)
			return (1);
		for (int i = 0; i < arr[now].size(); i++)
		{
			int next = arr[now][i].first;
			int weight = arr[now][i].second;
			if (visit[next] == 0 && weight >= mid1)
			{
				a.push(next);
				visit[next] = 1;
			}
		}
	}
	return (0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<pair<int, int>>> arr(n + 1);
	for (long long j = 1; j <= m; j++)
	{
		cin >> temp >> temp1 >> temp2;
		arr[temp].push_back({ temp1, temp2 });
		arr[temp1].push_back({ temp, temp2 });
		if (temp2 > max1)
			max1 = temp2;
	}
	long from, to;
	cin >> from >> to;
	left1 = 0;
	right1 = max1 + 1;

	while (left1 + 1 < right1)
	{
		mid1 = (left1 + right1) / 2;
		if (bfs(mid1, arr, from, to) > 0)
			left1 = mid1; // 늘리기
		else
			right1 = mid1;  // 줄이기
	}
	cout << left1;
}