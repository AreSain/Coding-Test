#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct ans {
	int start;
	int end;
}	ans;

bool cmp(ans a, ans b)
{
	if (a.end == b.end)
		return (a.start < b.start);
	else
		return (a.end < b.end);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp1, tmp2;
	cin >> n;
	ans temp;
	vector<ans>v;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp1 >> tmp2;
		temp.start = tmp1;
		temp.end = tmp2;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	int end = 0;
	int total = 0;

	for (int i = 0; i < v.size(); i++)
	{
		temp = v[i];
		// cout << v[i].start << ' ' << v[i].end << '\n';
		if (end <= temp.start)
		{
			end = temp.end;
			total++;
		}
	}
	cout << total;
}