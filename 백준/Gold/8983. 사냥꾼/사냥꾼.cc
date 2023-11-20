#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef struct beast
{
	long long x;
	long long y;
	long long all;
	long long life;
} beast;

int cmp(beast a, beast b)
{
	return (a.all < b.all);
}

long long qwe(vector<beast> &ani, long long m, long long j, long long l, long long n, vector<int> &sa, long long die)
{
	long long left, right, mid;

	left = die - 1;
	right = n;
	while (left + 1 < right)
	{
		mid = (left + right) / 2;
		if (ani[mid].all <= sa[j] + l)
			left = mid;
		else
			right = mid;
	}
	return left;
}

long long check(long long m, long long n, vector<int> &sa, vector<beast> &ani, long long l)
{
	long long kill = 0, k, die = 0;
	for (long long j = 0; j < m; j++)
	{
		k = qwe(ani, m, j, l, n, sa, die);
		for (long long i = die; i <= k && k < n; i++)
		{
			long long cut = 0;
			if (ani[i].life == 1)
			{
				cut = abs(ani[i].x - sa[j]) + ani[i].y;
				if (cut <= l)
				{
					ani[i].life = 0;
					kill++;
				}
			}
		}
		die = k + 1;
	}
	return kill;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m, l, temp, x, y, mid, max = 0;
	vector<int> sa;
	vector<beast> ani;

	cin >> m >> n >> l;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		sa.push_back(temp);
	}
	sort(sa.begin(), sa.end());

	for (int i = 0; i < n; i++)
	{
		beast tp;
		cin >> x >> y;
		tp.x = x;
		tp.y = y;
		tp.all = x + y;
		tp.life = 1;
		ani.push_back(tp);
	}
	sort(ani.begin(), ani.end(), cmp);
	cout << check(m, n, sa, ani, l);
}