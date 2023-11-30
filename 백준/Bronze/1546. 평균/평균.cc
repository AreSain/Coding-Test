#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double n, sum = 0;
	vector<double> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		v[i] = v[i] * 100 / v[n - 1];
		sum += v[i];
	}
	cout << sum / n;
}