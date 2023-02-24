// 백준 11505: 구간 곱 구하기(골드 I)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX = 1000000;
const ll MOD = 1000000007;
ll N, M, K, a, b, c, startIdx, numbers[MAX], tree[MAX * 3 + 1];

// 초기화
void init() {
	// 1번: 트리의 크기 구하기
	startIdx = 1;
	while (startIdx <= N)
		startIdx *= 2;

	// 2번: 리프 노드의 값 tree에 삽입
	for (int i = 0; i < N; ++i)
		tree[startIdx + i] = numbers[i];

	// 3번: 나머지 tree 값 채우기
	for (ll i = startIdx - 1; i > 0; --i)
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
}

// 업데이트
void update(ll idx, ll before, ll after) {
	tree[idx] = after; // 초기화 2번
	idx /= 2;

	while (idx > 0) {
		tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD; // 초기화 3번
		idx /= 2;
	}
}

// 구간곱 구하기
ll getMul(ll left, ll right) {
	ll answer = 1;

	while (left <= right) {
		if (left % 2 == 1) {
			answer *= tree[left];
			answer %= MOD;
		}
		if (right % 2 == 0) {
			answer *= tree[right];
			answer %= MOD;
		}

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}

	return answer;
}

int main() {
	// 입력 1
	scanf("%lld %lld %lld", &N, &M, &K);
	for (int i = 0; i < N; ++i)
		scanf("%lld", &numbers[i]);

	init();

	// 입력 2
	for (int i = 0; i < M + K; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);

		// startIdx = 리프노드의 첫 index, b - 1 = b번째 수의 리프노드 index
		if (a == 1)
			update(startIdx + b - 1, tree[startIdx + b - 1], c);
		else
			printf("%lld\n", getMul(startIdx + b - 1, startIdx + c - 1));
	}

	return 0;
}