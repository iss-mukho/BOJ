#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i, * A, * B, sum = 0;
	cin >> N;
	A = new int[N];
	B = new int[N];
	for (i = 0; i < N; ++i)
		cin >> A[i];
	for (i = 0; i < N; ++i)
		cin >> B[i];
	sort(A, A + N);
	sort(B, B + N, greater<int>());
	for (i = 0; i < N; ++i)
		sum += A[i] * B[i];
	cout << sum << '\n';
	return 0;
}