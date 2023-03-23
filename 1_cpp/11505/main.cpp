// ���� 11505: ���� �� ���ϱ�(��� I)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX = 1000000;
const ll MOD = 1000000007;
ll N, M, K, a, b, c, startIdx, numbers[MAX], tree[MAX * 3 + 1];

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
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
}

// ������Ʈ
void update(ll idx, ll before, ll after) {
	tree[idx] = after; // �ʱ�ȭ 2��
	idx /= 2;

	while (idx > 0) {
		tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD; // �ʱ�ȭ 3��
		idx /= 2;
	}
}

// ������ ���ϱ�
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
	// �Է� 1
	scanf("%lld %lld %lld", &N, &M, &K);
	for (int i = 0; i < N; ++i)
		scanf("%lld", &numbers[i]);

	init();

	// �Է� 2
	for (int i = 0; i < M + K; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);

		// startIdx = ��������� ù index, b - 1 = b��° ���� ������� index
		if (a == 1)
			update(startIdx + b - 1, tree[startIdx + b - 1], c);
		else
			printf("%lld\n", getMul(startIdx + b - 1, startIdx + c - 1));
	}

	return 0;
}