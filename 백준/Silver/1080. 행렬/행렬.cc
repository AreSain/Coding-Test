#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[54][54];
int ans[54][54];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, flip = 0;

	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			arr[i][j] = str[j] - '0';
	}

	
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			ans[i][j] = str[j] - '0';
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (arr[i][j] != ans[i][j])
			{
				for (int k = i; k < i + 3; k++)
				{
					for (int l = j; l < j + 3; l++)
					{
						if (arr[k][l] == 0)
							arr[k][l] = 1;
						else
							arr[k][l] = 0;
					}
				}
				flip++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] != ans[i][j])
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << flip;
}