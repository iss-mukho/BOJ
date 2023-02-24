// ���� 1759: ��ȣ �����(��� V), https://www.acmicpc.net/problem/1759
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int L, C, vowelCount;
char temp;
bool checked[26];
vector<char> alphabet;
vector<char> output;

// ������ �� ��ȯ
int getVowelCount() {
	return checked['a' - 'a'] + checked['e' - 'a'] + checked['i' - 'a'] + checked['o' - 'a'] + checked['u' - 'a'];
}

void DFS(int idx, int cnt) {
	if (cnt == L) {
		vowelCount = getVowelCount();
		if (!vowelCount) return; // ���� 1: �ּ� �� ���� ����
		if (L - vowelCount < 2) return; // ���� 2: �ּ� �� ���� ����

		for (auto& o : output)
			printf("%c", o);
		printf("\n");
		return;
	}

	for (int i = idx + 1; i < C; ++i) {
		if (checked[alphabet[i] - 'a']) continue;

		output.push_back(alphabet[i]);
		checked[alphabet[i] - 'a'] = true;
		DFS(i, cnt + 1);
		output.pop_back();
		checked[alphabet[i] - 'a'] = false;
	}
}

int main() {
	// �Է�
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; ++i) {
		scanf(" %c", &temp);
		alphabet.push_back(temp);
	}

	// ó�� �� ���
	sort(alphabet.begin(), alphabet.end());
	for (int i = 0; i <= C - L; ++i) {
		output.push_back(alphabet[i]);
		checked[alphabet[i] - 'a'] = true;
		DFS(i, 1);
		output.pop_back();
		checked[alphabet[i] - 'a'] = false;
	}

	return 0;
}