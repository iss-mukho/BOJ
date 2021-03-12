#include <iostream>
#include <cmath>
using namespace std;
// 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다.
// 2: 
int main() {
	int check[10001]; // sqrt(10000) == 5081
	fill_n(check, 10001, 1);
	check[0] = 0;
	check[1] = 0;
	int T;
	cin >> T;
	// 소수 여부 판별
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
	// 테스트케이스 실행
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		// 짝수 = 소수 + 소수
		int low = 0, high = 10001;
		int i = 2; // 4 <= n <= 10000
		for (i; i <= n-2 && i<=n-i; i++) { // n = 소수 + (n-소수)
			if (check[i] == 0) // 소수가 아니면 no check
				continue;
			if (check[n - i] == 1) { // (n-소수)의 값이 소수라면
				if (n - (2 * i) < high - low) { // 그 차이가 가장 작은 값인가?
					low = i;
					high = n - i;
				}
			}
		}
		// 출력
		cout << low << ' ' << high << '\n';
	}
	return 0;
}