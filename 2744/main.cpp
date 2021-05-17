#include <iostream>
#include <string>
using namespace std;
int main() {
	string input;
	int len, i;
	cin >> input;
	len = input.size();
	for (i = 0; i < len; ++i) {
		if (input[i] - 0 >= 65 && input[i] - 0 <= 90)
			input[i] = char(input[i] + 32);
		else
			input[i] = char(input[i] - 32);
	}
	cout << input << '\n';
	return 0;
}