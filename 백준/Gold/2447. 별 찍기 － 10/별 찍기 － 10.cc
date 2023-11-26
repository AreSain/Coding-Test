#include <iostream>
#include <algorithm>
using namespace std;

int n;

void check(int x, int y, int size)
{
	if (size == 0)
		return ;
	if ((x / size) % 3 == 1 && (y / size) % 3 == 1)
		cout << " ";
	else
	{
		if (size / 3 == 0)
			cout << "*";
		else
			check(x, y, size / 3);
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
			check(i, j, n); 
		cout << '\n';
	}
}