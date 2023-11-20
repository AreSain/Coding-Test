#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int change_cnt = 0;
int k;

void swap(vector<int>& arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;

	change_cnt += 1;
	if (change_cnt == k)
	{
		cout << min(arr[a], arr[b]) << " " << max(arr[a], arr[b]) << endl;
		exit(0);
	}
}

int divide(vector<int>& arr, int left, int right) {
	int x = arr[right];
	int i = left - 1;

	for (int j = left; j < right; j++) {
		if (arr[j] <= x)
		{
			i++;
			swap(arr, i, j);
		}
	}

	if (i + 1 != right)
		swap(arr, i + 1, right);
	return i + 1;
}

void quickSort(vector<int>& arr, int left, int right) {
	if (left < right)
	{
		int pivot = divide(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, temp;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quickSort(arr, 0, n - 1);
	cout << -1;
}