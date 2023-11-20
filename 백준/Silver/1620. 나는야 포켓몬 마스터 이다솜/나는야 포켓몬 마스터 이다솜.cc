#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, ans;
	unordered_map<int, string> num_name;
	unordered_map<string, int> name_num;
	string pokemon;

	cin >> num >> ans;
	for (int i = 1; i <= num; i++)
	{
		cin >> pokemon;
		num_name[i] = pokemon;
		name_num[pokemon] = i;
	}
	for (int j = 0; j < ans; j++)
	{
		cin >> pokemon;
		if (isdigit(pokemon[0]))
		{
			num = stoi(pokemon);
			cout << num_name[num] << '\n';
		}
		else
			cout << name_num[pokemon] << '\n';
	}
}