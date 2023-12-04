#include <iostream>
#include <algorithm>
using namespace std;

int n, r, c, i = 1, ans = 0;

void check(int x, int y, int size)
{
	if (size == 0)				// 변의 길이가 0이며 그만
		return;
	if (y == r && x == c)		// 찾았으면 그만
	{
		cout << ans;
		return;
	}
	if (c < x + size && r < y + size && c >= x && r >= y)	// 범위 안에 (r, c)가 있을 경우 분할
	{
		check(x, y, size / 2);								// 왼쪽 위
		check(x + size / 2, y, size / 2);					// 오른쪽 위
		check(x, y + size / 2, size / 2);					// 왼쪽 아래
		check(x + size / 2, y + size / 2, size / 2);		// 오른쪽 아래
	}
	else
		ans += size * size;									// 없을경우 사각형의 크기만큼 더해준다.
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