#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, n, k;
	deque<int> deq;

	cin >> i >> n;
	for (int j = 1; j <= i; j++)
		deq.push_back(j);
	while (i > n)
	{
		k = 0;
		deq.push_back(deq.front());
		while (k < n)
		{
			deq.pop_front();
			k++;
		}
		i = i - n + 1;
	}
	cout << deq.front();
}