#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, a, b, i, j, len;
	string s;
	char temp;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin >> a >> b;
		cin >> s;
		len = s.length();
		for (j = 0; j < len; ++j) {
			temp = char(65+ ((a * (int(s[j])-65) + b) % 26));
			cout << temp;
		}
		cout << '\n';
	}
	return 0;
}