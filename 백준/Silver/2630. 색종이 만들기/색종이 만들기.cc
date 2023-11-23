#include <iostream>
#include <algorithm>
using namespace std;

int arr[128][128];
int n, white = 0, blue = 0;

void check(int gox, int goy, int size)
{
	int target = arr[goy][gox], cnt = 0;

	for (int y = goy; y < goy + size; y++)
	{
		for (int x = gox; x < gox + size; x++)
		{
			if (arr[y][x] == target)
				cnt++;
		}
	}
	if (cnt != size * size)
	{
		check (gox, goy, size / 2);
		check (gox + size / 2, goy, size / 2);
		check (gox, goy + size / 2, size / 2);
		check (gox + size / 2, goy + size / 2, size / 2);
	}
	else
	{
		if (target == 1)
			blue++;
		else
			white++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	check(0, 0, n);
	cout << white << "\n" << blue << "\n";
}