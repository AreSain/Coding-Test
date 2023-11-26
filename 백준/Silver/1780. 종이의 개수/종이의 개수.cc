#include <iostream>
#include <algorithm>
using namespace std;

int arr[2200][2200];
int n, mi = 0, pl = 0, ze = 0;

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
		check(gox, goy, size / 3);
		check(gox, goy + size / 3, size / 3);
		check(gox, goy + 2 * size / 3, size / 3);
		check(gox + size / 3, goy, size / 3);
		check(gox + size / 3, goy + size / 3, size / 3);
		check(gox + size / 3, goy + 2 * size / 3, size / 3);
		check(gox + 2 * size / 3, goy, size / 3);
		check(gox + 2 * size / 3, goy + size / 3, size / 3);
		check(gox + 2 * size / 3, goy + 2 * size / 3, size / 3);
	}
	else
	{
		if (target == 1)
			pl++;
		else if (target == 0)
			ze++;
		else
			mi++;
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
	cout << mi << "\n" << ze << "\n" << pl;
}