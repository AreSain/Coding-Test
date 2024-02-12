#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, t, cnt, ans, air, air2;
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int check(int map[52][52], int t)
{
	if (t == 0)
	{
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				ans += map[i][j];
			}
		}
		return ans;
	}
	int temp[52][52] = { 0, };
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] > 4)
			{
				cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int cx = j + dx[k];
					int cy = i + dy[k];

					if (cx > 0 && cy > 0 && cx <= c && cy <= r)
					{
						if ((cx == 1 && cy == air) || (cx == 1 && cy == air2))
							continue;
						temp[cy][cx] += map[i][j] / 5;
						cnt++;
					}
				}
				temp[i][j] += map[i][j] - (map[i][j] / 5) * cnt;
			}
			else if (map[i][j] != -1)
			{
				temp[i][j] += map[i][j];
			}
		}
	}
/*
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << temp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/
	for (int i = air; i > 1; i--) {
		temp[i][1] = temp[i - 1][1];
	}
	for (int i = 1; i < c; i++) {
		temp[1][i] = temp[1][i + 1];
	}
	for (int i = 1; i < air; i++) {
		temp[i][c] = temp[i + 1][c];
	}
	for (int i = c; i > 1; i--) {
		temp[air][i] = temp[air][i - 1];
	}
	temp[air][1] = 0;

	for (int i = air2; i < r; i++) {
		temp[i][1] = temp[i + 1][1];
	}
	for (int i = 1; i < c; i++) {
		temp[r][i] = temp[r][i + 1];
	}
	for (int i = r; i > air2; i--) {
		temp[i][c] = temp[i - 1][c];
	}
	for (int i = c; i > 1; i--) {
		temp[air2][i] = temp[air2][i - 1];
	}
	temp[air2][1] = 0;
	temp[air][2] = 0;
	temp[air2][2] = 0;

	return check(temp, t - 1);
}

int main()
{
	int map[52][52];
	int flag = 0;
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
			if (flag == 0 && map[i][j] == -1)
			{
				flag++;
				air = i;
				air2 = i + 1;
			}
		}
	}
//	cout << air << ' ' << air2 << '\n';
	cout << check(map, t);
}