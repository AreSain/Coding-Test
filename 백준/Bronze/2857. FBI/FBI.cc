#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ch;
	int n = 1, i = 0, flag = 1, print = 1;

	while (n <= 5)
	{
		cin >> ch;
		i = 0;
		while (ch[i] != '\0')
		{
	
			if (ch[i] == 'F' && print == 1)
			{
				if (ch[++i] == 'B')
					if (ch[++i] == 'I')
					{
						cout << n;
                        if (n != 5)
                      		  cout << ' ';
						flag++;
						print = 0;
					}
			}
			else
				i++;
		}
		print = 1;
		n++;
	}
	if (flag == 1)
		cout << "HE GOT AWAY!";
}