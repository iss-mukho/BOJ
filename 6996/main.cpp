#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T, i;
	string a, b, s1, s2;
	bool check;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin.ignore();
		cin >> a >> b;
		check = true;
		if (a.length() != b.length())
			check = false;
		else {
			s1 = a;
			s2 = b;
			sort(s1.begin(), s1.end());
			sort(s2.begin(), s2.end());
			if (s1 != s2)
				check = false;
		}
		if (check)
			cout << a << " & " << b << " are anagrams.\n";
		else
			cout << a << " & " << b << " are NOT anagrams.\n";
	}
	return 0;
}