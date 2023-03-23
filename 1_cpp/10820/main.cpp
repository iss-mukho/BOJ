#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int len, i, a, b, c, d; // a:소문자, b:대문자, c:숫자, d:공백
	string input;
	while (1) {
		getline(cin, input);
		len = input.size();
		if (len == 0)
			break;
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		for (i = 0; i < len; ++i) {
			if (input[i] - 0 >= 65 && input[i] - 0 <= 90)
				++b;
			else if (input[i] - 0 >= 97 && input[i] - 0 <= 122)
				++a;
			else if (input[i] - 0 == 32)
				++d;
			else if (input[i] - 0 >= 48 && input[i] - 0 <= 89)
				++c;
		}
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
	return 0;
}