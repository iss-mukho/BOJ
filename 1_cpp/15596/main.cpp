#include <iostream>
using namespace std;

long long sum(int* A, int N);
int main() {
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << sum(a, n) << '\n';

	return 0;
}
long long sum(int* A, int N) {
	long long result = 0;
	for (int i = 0; i < N; i++)
		result += A[i];

	return result;
}