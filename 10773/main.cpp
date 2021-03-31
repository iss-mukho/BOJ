#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main() {
	int K, n, i, sum = 0;
	cin >> K;
	for (i = 0; i < K; ++i) {
		cin >> n;
		if (n)
			s.push(n);
		else
			s.pop();
	}
	i = s.size();
	while (i > 0) {
		sum += s.top();
		s.pop();
		--i;
	}
	cout << sum << '\n';
	return 0;
}