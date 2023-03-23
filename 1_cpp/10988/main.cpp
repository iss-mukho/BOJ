#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	int i, j, result = 1;
	cin >> input;
	i = 0;
	j = input.size() - 1;
	while (i <= j) {
		if (input[i] != input[j]) {
			result = 0;
			break;
		}
		++i;
		--j;
	}
	cout << result << '\n';
	return 0;
}