#include <iostream>
#include <string>
using namespace std;

int main() {
	int alphabet[26];
	fill_n(alphabet, 26, -1);
	string S;
	getline(cin, S);
	for (int i = 0; i < S.size(); i++) {
		int index = (int)S[i] - 97;
		if (alphabet[index] == -1)
			alphabet[index] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << ' ';
	cout << '\n';
	return 0;
}