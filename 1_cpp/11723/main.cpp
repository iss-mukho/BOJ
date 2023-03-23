// 백준 11723: 집합(실버 V)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 20;

int M, x;
bool S[MAX + 1];
char cmd[8];

int main() {
	scanf("%d", &M);

	while (M--) {
		scanf("%s", &cmd);

		if (cmd[0] == 'a') {
			if (cmd[1] == 'd') {
				scanf("%d", &x);
				if(!S[x]) S[x] = true;
			}
			else
				for (int i = 1; i <= MAX; ++i)
					S[i] = true;
		}
		else if (cmd[0] == 'r') {
			scanf("%d", &x);
			if (S[x]) S[x] = false;
		}
		else if (cmd[0] == 'c') {
			scanf("%d", &x);
			if (S[x]) printf("1\n");
			else printf("0\n");
		}
		else if (cmd[0] == 't') {
			scanf("%d", &x);
			S[x] = !S[x];
		}
		else
			for (int i = 1; i <= MAX; ++i)
				S[i] = false;
	}

	return 0;
}