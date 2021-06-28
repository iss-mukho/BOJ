#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, temp;
	bool isOpen = false;
	getline(cin, S);

	for (char s : S) {
		if (isOpen) {
			if (s == '>') {
				cout << temp << '>';
				temp = "";
				isOpen = false;
			}
			else
				temp += s;
		}
		else {
			if (s == '<') {
				if (temp.length() != 0)
					cout << temp;
				temp = "<";
				isOpen = true;
			}
			else if (s == ' ') {
				cout << temp << ' ';
				temp = "";
			}
			else
				temp = s + temp;
		}
	}
	if (temp.length() != 0)
		cout << temp << '\n';

	return 0;
}