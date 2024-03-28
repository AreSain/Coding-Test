#include <iostream>
#include <string>

int main() {
	std::string s , temp = "";
	int sum = 0;
	char flag = '+';
	std::cin >> s;

	for(int i = 0; i <= s.length(); i++) {
		if(i < s.length() && (s[i] >= '0' && s[i] <= '9')) {
			temp += s[i];
		} else {
			if(flag == '-') {
				sum -= stoi(temp);
			} else {
				sum += stoi(temp);
			}
			temp = "";
			if(i < s.length() && s[i] == '-') {
				flag = '-';
			}
		}
	}

	std::cout << sum;
	return 0;
}