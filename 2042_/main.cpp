/* 백준 2042: 구간 합 구하기(골드 I)
* Index Tree: Bottom-Up
* 자가 코드로 다시 풀어봄
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX = 1000000;
ll N, M, K, a, b, c, startIdx, numbers[MAX], tree[MAX * 2 + 1];

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
	for (int i = startIdx - 1; i > 0; --i)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

// 업데이트: n번째 값 += (변경값 - 기존값)
void update(int idx, ll diff) {
	while (idx > 0) {
		tree[idx] += diff;
		idx /= 2;
	}
}

// 구간합 구하기
ll getSum(int left, int right) {
	ll answer = 0;

	while (left <= right) {
		if (left % 2 == 1) answer += tree[left];
		if (right % 2 == 0) answer += tree[right];

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
		if (a == 1)// Update
			update(startIdx + b - 1, c - tree[startIdx + b - 1]);
		else // Prefix Sum
			printf("%lld\n", getSum(startIdx + b - 1, startIdx + c - 1));
	}

	return 0;
}