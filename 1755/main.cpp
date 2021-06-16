#include <iostream>
#include <string>
#include <map>
using namespace std;
string int_to_string[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int M, N, i, cnt = 0;
	cin >> M >> N;
	for (i = M; i <= N; ++i) {
		string temp;
		if (i >= 10)
			temp = int_to_string[i / 10] + " " + int_to_string[i % 10];
		else
			temp = int_to_string[i % 10];
		m.insert({ temp, i });
	}

	for (auto iter : m) {
		cout << iter.second;
		if (++cnt < 10)
			cout << ' ';
		else {
			cnt = 0;
			cout << '\n';
		}	
	}
	
	return 0;
}