#include <iostream>
#include <string>
using namespace std;

int main() {
	int alphabet[26] = {0,};
	string s;
	cin >> s;
	// 65A 90Z 97a 122z ~32
	for (int i = 0; i < s.size(); i++) {
		if ((int)s[i] >= 97 and (int)s[i] <= 122)
			s[i] -= 32;
		alphabet[s[i]-65] += 1;
	}
	int idx = 0;
	int max = alphabet[idx];
	bool du = false;
	if (s.size() > 1) {
		for (int i = 1; i < 26; i++) {
			if (alphabet[idx] < alphabet[i]) {
				idx = i;
				max = alphabet[idx];
				du = false;
			}
			else if (alphabet[idx] == alphabet[i])
				du = true;
		}
	}
	else
		idx = ((int)s[0])-65;
	if (alphabet[idx] == 0 || du == true)
		cout << "?" << '\n';
	else
		cout << (char)(idx+65) << '\n';
	return 0;
}