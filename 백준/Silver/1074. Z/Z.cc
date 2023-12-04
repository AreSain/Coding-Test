#include <iostream>
#include <algorithm>
using namespace std;

int n, r, c, i = 1, ans = 0;

void check(int x, int y, int size)
{
	if (size == 0)
		return;
	if (y == r && x == c)
	{
		cout << ans;
		return;
	}
	if (c < x + size && r < y + size && c >= x && r >= y)
	{
		check(x, y, size / 2);
		check(x + size / 2, y, size / 2);
		check(x, y + size / 2, size / 2);
		check(x + size / 2, y + size / 2, size / 2);
	}
	else
		ans += size * size;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;
	while (n > 0)
	{
		i *= 2;
		n--;
	}
	check(0, 0, i);
}