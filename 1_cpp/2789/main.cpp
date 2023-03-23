#include <iostream>
#include <string>
using namespace std;
int main() {
	string input, cut = "CAMBRIDGE", output;
	int i, j, len;
	bool cont = false;
	cin >> input;
	len = input.length();
	for (i = 0; i < len; ++i) {
		cont = true;
		for (j = 0; j < 9; ++j) {
			if (input[i] == cut[j]) {
				cont = false;
				break;
			}
		}
		if (cont)
			output += input[i];
	}
	cout << output << '\n';
	return 0;
}