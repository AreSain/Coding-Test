#include <iostream>
using namespace std;

void call(int n, int a, int b, int c)
{
	if (n == 1)
	{
		cout << a << ' ' << c << '\n';
	}
	else
	{
		call(n - 1, a, c, b); // a 에서 b로 옮기기
		cout << a << ' ' << c << '\n';
		call(n - 1, b, a, c); // b에서 c로 옮기기
	}
}

int main()
{
	int n, temp, ans = 1;

	cin >> n;
	temp = n;
	while (temp > 0)
	{
		ans = ans * 2;
		temp--;
	}
	cout << ans - 1 << '\n';
	call(n, 1, 2, 3);
}