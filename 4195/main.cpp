// ���� 4195: ģ�� ��Ʈ��ũ(��� II)
/** ù �õ� : �ð� �ʰ�
* �� ��° �õ�: O(N)�� �ڵ带 O(1)�� ����
*	- 44% Ʋ�Ƚ��ϴ�
*	- ��� �� parent[x]�� �ƴ�, parent[findParent(x)]�� ��ħ
* �� ��° �õ�: �¾ҽ��ϴ�!!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 200000;
int TC, F, cnt=0;
vector<pii> parent;
char a[25], b[25];
map<string, int> dic; // {name: idx}

void subUnion(int l, int h) {
	parent[h].first = l;
	parent[l].second += parent[h].second;
}
int findParent(int x) {
	if (parent[x].first != x) parent[x].first = findParent(parent[x].first);
	return parent[x].first;
}
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) subUnion(a, b);
	else subUnion(b, a);
}

void addDic(char s[]) {
	if (dic.find(s) == dic.end()) {
		dic[s] = ++cnt;
		parent.push_back(pii(cnt, 1));
	}
}

int main() {
	// �Է�
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &F);

		// �ʱ�ȭ
		parent.clear();
		parent.push_back(pii(0, 0)); // dummy
		dic.clear();
		cnt = 0;
		
		for (int i = 0; i < F; ++i) {
			scanf("%s %s", &a, &b);
			addDic(a); addDic(b);
			int x = dic[a], y = dic[b];

			// ó��
			if (findParent(x) != findParent(y))
				unionParent(x, y);

			// ���
			printf("%d\n", parent[findParent(x)].second);
		}
	}
	
	return 0;
}