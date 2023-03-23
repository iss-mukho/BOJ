#include <iostream>
#include <cmath>
using namespace std;
// 2���� ū ��� ¦���� �� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
// 2: 
int main() {
	int check[10001]; // sqrt(10000) == 5081
	fill_n(check, 10001, 1);
	check[0] = 0;
	check[1] = 0;
	int T;
	cin >> T;
	// �Ҽ� ���� �Ǻ�
	for (int i = 2; i <= 10000; i++) {
		for (int j = 2; j <= sqrt(10000); j++) {
			if (check[i] == 0)
				continue;
			if (i != j && i % j == 0) {
				check[i] = 0;
				break;
			}
		}
	}
	// �׽�Ʈ���̽� ����
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		// ¦�� = �Ҽ� + �Ҽ�
		int low = 0, high = 10001;
		int i = 2; // 4 <= n <= 10000
		for (i; i <= n-2 && i<=n-i; i++) { // n = �Ҽ� + (n-�Ҽ�)
			if (check[i] == 0) // �Ҽ��� �ƴϸ� no check
				continue;
			if (check[n - i] == 1) { // (n-�Ҽ�)�� ���� �Ҽ����
				if (n - (2 * i) < high - low) { // �� ���̰� ���� ���� ���ΰ�?
					low = i;
					high = n - i;
				}
			}
		}
		// ���
		cout << low << ' ' << high << '\n';
	}
	return 0;
}