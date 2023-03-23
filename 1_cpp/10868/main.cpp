// ���� 10868: �ּڰ�(��� I), https://www.acmicpc.net/problem/10868
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000001;
const int MAX = 100000;
int N, M, a, b, startIdx, numbers[MAX], tree[MAX * 3 + 1];
// tree�� ũ��� 2^m * 2

// �ʱ�ȭ
void init() {
	// 1��: Ʈ���� ũ�� ���ϱ�
	startIdx = 1;
	while (startIdx <= N)
		startIdx *= 2;

	// 2��: ���� ����� �� tree�� ����
	for (int i = 0; i < N; ++i)
		tree[startIdx + i] = numbers[i];

	// 3��: ������ tree �� ä���
	for (int i = startIdx - 1; i > 0; --i)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

// ���� �ּڰ� ���ϱ�
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
	// �Է� 1
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", &numbers[i]);

	init();

	// �Է� 2
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);

		// startIdx = ��������� ù index, n - 1 = n��° ���� ������� index
		printf("%d\n", getMin(startIdx + a - 1, startIdx + b - 1));// Prefix Min
	}

	return 0;
}