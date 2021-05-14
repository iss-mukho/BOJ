#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input, output;
	int len, i;
	cin >> input;
	len = input.size();
	for (i = 0; i < len; ++i)
		if (input[i] - 0 >= 65 && input[i] - 0 <= 90)
			output += input[i];
	cout << output << '\n';
	return 0;
}