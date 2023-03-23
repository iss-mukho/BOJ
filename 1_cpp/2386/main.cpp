#include <iostream>
#include <string>
using namespace std;
int main() {
	char chr;
	string str;
	int cnt, len, i;
	while (true) {
		cin >> chr;
		if (chr == '#')
			break;
		cnt = 0;
		getline(cin, str);
		len = str.length();
		for (i = 0; i < len; ++i) 
			if (chr-0 == str[i]-0 || chr - 0 == str[i] + 32)
				++cnt;
		cout << chr << ' ' << cnt << '\n';
	}
	return 0;
}