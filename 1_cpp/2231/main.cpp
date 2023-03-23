#include <iostream>
#include <string>
using namespace std;
int main() {
	string input;
	cin >> input;
	int N = stoi(input);
	int a = 0;
	string temp;
	for (int i = 1; i < N; i++) {
		a += i;
		temp = to_string(i);
		for (int j = 0; j < temp.size(); j++)
			a += (temp[j] - '0');
		if (a == N) {
			a = i;
			break;
		}
		else
			a = 0;
	}
	cout << a << '\n';
	return 0;
}