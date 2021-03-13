#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int* card = new int[N];
	for (int i = 0; i < N; i++)
		cin >> card[i];
	int sum = 0;
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				int temp = card[i] + card[j] + card[k];
				if (M < temp)
					continue;
				if (M - temp < M - sum)
					sum = temp;
			}
		}
	}
	cout << sum << '\n';
	return 0;
}