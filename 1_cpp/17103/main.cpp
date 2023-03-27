// 백준 17103: 골드바흐 파티션, https://www.acmicpc.net/problem/17103
#include <iostream>
using namespace std;

const int MAX = 1000001;
bool number[MAX];
int T, N;

// 에라토스테네스의 체
void getPrimeNumber() {
	fill_n(number, MAX, true);
	number[0] = false;
	number[1] = false;

	for (int i = 2; i < MAX; ++i) {
		if (!number[i]) continue;
		for (int j = 2; i * j < MAX; ++j) number[i * j] = false;
	}
}

int getGoldbach(int num) {
	int answer = 0;

	for (int i = 2; i < num / 2 + 1; ++i)
		if (number[i] && number[num - i]) ++answer;

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getPrimeNumber();

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << getGoldbach(N) << '\n';
	}

	return 0;
}