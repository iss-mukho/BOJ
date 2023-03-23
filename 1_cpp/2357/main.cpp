// ���� 2357: �ּڰ��� �ִ�(��� I), https://www.acmicpc.net/problem/2357
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000001;
const int MAX = 100000;
int N, M, a, b, c, startIdx, numbers[MAX], minTree[MAX * 3 + 1], maxTree[MAX * 3 + 1];
// tree�� ũ��� 2^m * 2

// �ʱ�ȭ
void init() {
	// 1��: Ʈ���� ũ�� ���ϱ�
	startIdx = 1;
	while (startIdx <= N)
		startIdx *= 2;

	// 2��: ���� ����� �� tree�� ����
	for (int i = 0; i < N; ++i) {
		minTree[startIdx + i] = numbers[i];
		maxTree[startIdx + i] = numbers[i];
	}
		
	// 3��: ������ tree �� ä���
	for (int i = startIdx - 1; i > 0; --i) {
		minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
		maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
	}
		
}

// ���� �ּڰ� ���ϱ�
int getMin(int left, int right) {
	int ansMin = INF;

	while (left <= right) {
		if (left % 2 == 1) ansMin = min(ansMin, minTree[left]);
		if (right % 2 == 0) ansMin = min(ansMin, minTree[right]);

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}

	return ansMin;
}

// ���� �ִ� ���ϱ�
int getMax(int left, int right) {
	int ansMax = 0;

	while (left <= right) {
		if (left % 2 == 1) ansMax = max(ansMax, maxTree[left]);
		if (right % 2 == 0) ansMax = max(ansMax, maxTree[right]);

		left = (left + 1) / 2;
		right = (right - 1) / 2;
	}

	return ansMax;
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
		printf("%d %d\n", getMin(startIdx + a - 1, startIdx + b - 1), getMax(startIdx + a - 1, startIdx + b - 1));
	}

	return 0;
}