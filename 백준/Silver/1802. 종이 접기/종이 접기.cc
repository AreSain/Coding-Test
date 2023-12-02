#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int check(int* arr, int left, int right)
{
	if (left >= right)
	{
		return (1);
	}

	int go = left;
	int out = right;

	while (left < right)
	{
		if (arr[left++] == arr[right--])
			return (0);
	}

	return (check(arr, go, out / 2 - 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[3001];
	string str;
	int t, temp;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			arr[j] = str[j];
		}
		if (str.size() == 1)
			temp = 1;
		else
			temp = check(arr, 0, str.size() - 1);
		if (temp == 0)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}
}