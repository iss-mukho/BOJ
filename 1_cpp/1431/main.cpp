#include <iostream>
#include <string>
using namespace std;
void Serial_Sort(string* str, int n);
string* input;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i;
	cin >> N;
	input = new string[N];
	for (i = 0; i < N; ++i)
		cin >> input[i];
	Serial_Sort(input, N);
	for (i = 0; i < N; ++i)
		cout << input[i] << '\n';
	delete []input;
	return 0;
}
void Serial_Sort(string* str, int n) {
	int i, j, idx;
	for (i = 0; i < n - 1; ++i) {
		idx = i;
		string temp;
		for (j = i + 1; j < n; ++j) {
			if (str[idx].length() != str[j].length()) {
				if (str[j].length() < str[idx].length())
					idx = j;
			}
			else {
				int k, idx_int = 0, j_int = 0, len = str[idx].length();
				for (k = 0; k < len; ++k) {
					if (str[idx][k] - '0' >= 0 && str[idx][k] - '0' <= 9)
						idx_int += str[idx][k] - '0';
					if (str[j][k] - '0' >= 0 && str[j][k] - '0' <= 9)
						j_int += str[j][k] - '0';
				}
				if (j_int != idx_int) {
					if (j_int < idx_int)
						idx = j;
				}
				else {
					if (str[j] < str[idx])
						idx = j;
				}
			}
		}
		if (i != idx) {
			temp = str[i];
			str[i] = str[idx];
			str[idx] = temp;
		}
	}
}