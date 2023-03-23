/* ���� 2042: ���� �� ���ϱ�(��� I)
* Index Tree: Bottom-Up
* �ڰ� �ڵ�� �ٽ� Ǯ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX = 1000000;
ll N, M, K, a, b, c, startIdx, numbers[MAX], tree[MAX * 2 + 1];

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
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

// ������Ʈ: n��° �� += (���氪 - ������)
void update(int idx, ll diff) {
	while (idx > 0) {
		tree[idx] += diff;
		idx /= 2;
	}
}

// ������ ���ϱ�
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
	// �Է� 1
	scanf("%lld %lld %lld", &N, &M, &K);
	for (int i = 0; i < N; ++i)
		scanf("%lld", &numbers[i]);

	init();

	// �Է� 2
	for (int i = 0; i < M + K; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);

		// startIdx = ��������� ù index, b - 1 = b��° ���� ������� index
		if (a == 1)// Update
			update(startIdx + b - 1, c - tree[startIdx + b - 1]);
		else // Prefix Sum
			printf("%lld\n", getSum(startIdx + b - 1, startIdx + c - 1));
	}

	return 0;
}