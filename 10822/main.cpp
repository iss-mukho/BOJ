#include <iostream>
#include <string>
using namespace std;
int main() {
	string S, temp;
	int sum = 0, i, len;
	cin >> S;
	len = S.length();
	for (i = 0; i < len; ++i) {
		if (S[i] != ',')
			temp += S[i];
		else {
			sum += stoi(temp);
			temp = "";
		}
	}
	sum += stoi(temp);
	cout << sum << '\n';
	return 0;
}