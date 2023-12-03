#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

long long d, x, y, dx = 0, dy = 0;
string str;

void finddxdy(long long index, long long rowlen)
{
	if (rowlen == 1)
		return;
	if (str[index] == '1')
	{
		dx += rowlen / 2; 
		dy += rowlen / 2;
	}
	else if (str[index] == '2')
	{
		dy += rowlen / 2;
	}
	else if (str[index] == '3')
	{
		;
	}
	else
	{
		dx += rowlen / 2;
	}
	finddxdy(index + 1, rowlen / 2);
}

void getwhere(long long rowlen)
{
	while (rowlen > 1)
	{
		rowlen /= 2;
		if (dx >= rowlen && dy >= rowlen)
		{
			cout << "1";
			dx -= rowlen;
			dy -= rowlen;
		}
		else if (dx < rowlen && dy >= rowlen)
		{
			cout << "2";
			dy -= rowlen;
		}
		else if (dx < rowlen && dy < rowlen)
		{
			cout << "3";
		}
		else
		{
			cout << "4";
			dx -= rowlen;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long rowlen;
	cin >> d >> str >> x >> y;

	rowlen = pow(2, str.size());
	finddxdy(0, rowlen);
	dx += x;
	dy += y;
	if (dx < 0 || dy < 0 || dx >= rowlen || dy >= rowlen)
	{
		cout << "-1";
		return 0;
	}
	getwhere(rowlen);
}