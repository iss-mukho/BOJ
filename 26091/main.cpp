// ���� 26091: ������ ����Ʈ���� ��ī����(�ǹ� I)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, a, low, high, answer;
vector<int> abil;

int main() {
	// �Է�
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a);
		abil.push_back(a);
	}

	// ó��
	sort(abil.begin(), abil.end());
	low = 0, high = N - 1;
	while (low < high) {
		if (abil[low] + abil[high] < M) {
			++low;
			continue;
		}
		++answer;
		++low; --high;
	}

	// ���
	printf("%d\n", answer);

	return 0;
}