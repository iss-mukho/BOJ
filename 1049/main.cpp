#include <iostream>
#include <algorithm>
using namespace std;

int N, M, p, o, costP = 1001, costO = 1001, answer = 0, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> p >> o;
		costP = min(costP, p);
		costO = min(costO, o);
	}

	// 처리
	if (costP >= costO * 6) // 오직 낱개
		answer = costO * N;
	else {
		if (costP < costO) { // 오직 패키지
			if (N % 6 == 0) // N의 배수
				answer = costP * (N / 6);
			else // (N-1) + 나머지
				answer = costP * (N / 6) + costP;
		}
		else {
			if(N%6==0) // 오직 패키지
				answer = costP * (N / 6);
			else { // 패키지 낱개
				r = costO * (N % 6); // 나머지 가격
				if (costP < r) // (N-1) + 나머지(패키지)
					answer = costP * (N / 6) + costP;
				else // (N-1) + 나머지(남음)
					answer = costP * (N / 6) + r;
			}
		}
	}
	
	// 출력
	cout << answer << '\n';

	return 0;
}