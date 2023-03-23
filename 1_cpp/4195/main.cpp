// 백준 4195: 친구 네트워크(골드 II)
/** 첫 시도 : 시간 초과
* 두 번째 시도: O(N)의 코드를 O(1)로 줄임
*	- 44% 틀렸습니다
*	- 출력 시 parent[x]가 아닌, parent[findParent(x)]로 고침
* 세 번째 시도: 맞았습니다!!
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
	// 입력
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &F);

		// 초기화
		parent.clear();
		parent.push_back(pii(0, 0)); // dummy
		dic.clear();
		cnt = 0;
		
		for (int i = 0; i < F; ++i) {
			scanf("%s %s", &a, &b);
			addDic(a); addDic(b);
			int x = dic[a], y = dic[b];

			// 처리
			if (findParent(x) != findParent(y))
				unionParent(x, y);

			// 출력
			printf("%d\n", parent[findParent(x)].second);
		}
	}
	
	return 0;
}