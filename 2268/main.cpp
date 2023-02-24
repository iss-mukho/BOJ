// ���� 2268: ������ ��(��� I)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX = 1000000;
ll N, M, a, b, c, startIdx, numbers[MAX], tree[MAX * 3 + 1];

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
	for (ll i = startIdx - 1; i > 0; --i)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

// ������Ʈ: n��° �� += (���氪 - ������)
void update(ll idx, ll diff) {
	while (idx > 0) {
		tree[idx] += diff;
		idx /= 2;
	}
}

// ������ ���ϱ�
ll getSum(ll left, ll right) {
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
	scanf("%lld %lld", &N, &M);

	init();

	// �Է� 2
	for (int i = 0; i < M; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);

		// startIdx = ��������� ù index, b - 1 = b��° ���� ������� index
		if (a == 0) { // Sum
			if (b > c) {
				ll temp = c;
				c = b;
				b = temp;
			}
			printf("%lld\n", getSum(startIdx + b - 1, startIdx + c - 1));
		}
		else // Modify
			update(startIdx + b - 1, c - tree[startIdx + b - 1]);
	}

	return 0;
}