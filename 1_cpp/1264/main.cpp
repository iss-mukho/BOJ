#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input, moeum = "aeiouAEIOU";
	int len, i, cnt;
	while (true) {
		getline(cin, input);
		if (input == "#")
			break;
		cnt = 0;
		len = input.length();
		for (i = 0; i < len; ++i) {
			if(moeum.find(input[i]) != -1)
				++cnt;
		}
		cout << cnt << '\n';
	}
	return 0;
}