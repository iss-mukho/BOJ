/* ���� 10942: �Ӹ����?(��� IV), https://www.acmicpc.net/problem/10942
* �õ� 1: ���ڿ� �����⸦ �̿��� �� -> �ð� �ʰ�
* �õ� 2: �� �����͸� �̿��� �� -> Ʋ�Ƚ��ϴ�
* �õ� 3: ���ڰ� �� �ڸ� ���� �ƴϾ���, ���ڿ����� ���ͷ� ���� -> �ð� �ʰ�
* �õ� 4: HELP- ���̳��� ���α׷���?
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2000;

int N, M, S, E, num;
int number[MAX + 1];
bool dp[MAX+1][MAX+1];

int main() {
	// �Է�: ������ ũ��
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &number[i]); // �Է�: ����
		dp[i][i] = true; // �ʱ�ȭ
	}

	// ���ӵ� �� �ʱ�ȭ
	for (int i = 1; i < N; ++i)
		if (number[i] == number[i + 1])
			dp[i][i + 1] = true;

	// DP ����: �Ųٷ�
	for (int i = N - 1; i > 0; --i)
		for (int j = i + 2; j <= N; ++j)
			if (number[i] == number[j] && dp[i + 1][j - 1]) // [S:E]�� �Ӹ�����̷��� [S+1:E-1]�� �Ӹ�����̾�� �Ѵ�
				dp[i][j] = true;
	
	// �Է�: ������ ����
	scanf("%d", &M);

	while (M--) {
		scanf("%d %d", &S, &E); // �Է�: ����
		printf("%d\n", dp[S][E]); // ���
	}

	return 0;
}