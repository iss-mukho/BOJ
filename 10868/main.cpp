// 백준 10868: 최솟값(골드 I), https://www.acmicpc.net/problem/10868
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000001;
const int MAX = 100000;
int N, M, a, b, startIdx, numbers[MAX], tree[MAX * 3 + 1];
// tree의 크기는 2^m * 2

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
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

// 구간 최솟값 구하기
int getMin(int left, int right) {
	int ansMin = INF;

	while (left <= right) {
		if (left % 2 == 1) ansMin = min(ansMin, tree[left]);
		if (right % 2 == 0) ansMin = min(ansMin, tree[right]);

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}

	return ansMin;
}

int main() {
	// 입력 1
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", &numbers[i]);

	init();

	// 입력 2
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);

		// startIdx = 리프노드의 첫 index, n - 1 = n번째 수의 리프노드 index
		printf("%d\n", getMin(startIdx + a - 1, startIdx + b - 1));// Prefix Min
	}

	return 0;
}