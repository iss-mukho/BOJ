// 백준 13317: 한 번 남았다(골드 III)
#include <iostream>
using namespace std;
int main() {
	cout << 50 << ' ' << 49 << '\n';
	for (int i = 49; i > 0; --i) cout << i << ' ' << i + 1 << ' ' << -1 << '\n';
	return 0;
}