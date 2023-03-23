#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string N;
	cin >> N;
	sort(N.begin(), N.end());
	reverse(N.begin(), N.end());
	cout << N << '\n';
	return 0;
}