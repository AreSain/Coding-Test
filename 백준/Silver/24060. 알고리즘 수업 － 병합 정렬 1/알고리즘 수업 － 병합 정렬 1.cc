#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int flag = 0, k, cnt = 0;

void merge(vector<int>& A, int p, int q, int r)
{
    vector<int> tmp(r - p + 1);
    int i = p, j = q + 1, t = 0;

    while (i <= q && j <= r)
	{
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];

    i = p;
	t = 0;
	while (i <= r)
	{
		A[i++] = tmp[t++];
		cnt++;
		if (cnt == k)
		{
			flag = 1;
			cout << A[i - 1];
		}
	}
}

void merge_sort(vector<int>& A, int p, int r)
{
    if (p < r)
	{
        int q = (p + r) / 2;

        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n >> k;
	vector<int> A(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> A[i];

	merge_sort(A, 1, n);

	if (flag == 0)
		cout << "-1";
}