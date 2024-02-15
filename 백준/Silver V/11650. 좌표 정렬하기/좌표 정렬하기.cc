#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
vector<pair<int, int>> arr;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
}