#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int result[T];

	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;
		if ((A < 0 || A>10) && B < 0 || B>10)
			return 0;

		result[i] = A + B;
	}

	for (int i = 0; i < T; i++)
		cout << result[i] << endl;

	return 0;
}