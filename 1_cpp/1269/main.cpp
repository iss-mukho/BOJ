#include <iostream>
#include <algorithm>
using namespace std;
int A[200000];
int B[200000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, i, sd = 0;
	cin >> a >> b;
	for (i = 0; i < a; ++i)
		cin >> A[i];
	for (i = 0; i < b; ++i)
		cin >> B[i];
	
	sort(A, A + a);
	sort(B, B + b);

	for (i = 0; i < b; ++i)
		sd += binary_search(A, A + a, B[i]);
	for (i = 0; i < a; ++i)
		sd += binary_search(B, B + b, A[i]);

	cout << a+b-sd << '\n';
	return 0;
}