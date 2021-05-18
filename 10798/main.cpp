#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	string input[5];
	int i, j, len;
	for (i = 0; i < 5; ++i)
		cin >> input[i];
	for (j = 0; j < 15; ++j)
		for (i = 0; i < 5; ++i)
			if(j < input[i].size())
				cout << input[i][j];
	cout << '\n';
	return 0;
}