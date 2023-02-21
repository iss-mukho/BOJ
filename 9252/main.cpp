#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000;
char str1[MAX + 1], str2[MAX + 1];
int dp[MAX + 1][MAX + 1], a, b;

void print(int x, int y) {
	if (dp[x][y] == 0) return;

	if (str1[x - 1] == str2[y - 1]) {
		print(x - 1, y - 1);
		printf("%c", str1[x - 1]);
	}
	else {
		if (dp[x - 1][y] > dp[x][y - 1])
			print(x - 1, y);
		else
			print(x, y - 1);
	}
}

int main() {
	scanf("%s", &str1);
	scanf("%s", &str2);

	for (a = 0; str1[a]; ++a) {
		for (b = 0; str2[b]; ++b) {
			if (str1[a] == str2[b])
				dp[a + 1][b + 1] = dp[a][b] + 1;
			else
				dp[a + 1][b + 1] = max(dp[a + 1][b], dp[a][b + 1]);
		}
	}

	printf("%d\n", dp[a][b]);
	print(a, b);
	printf("\n");

	return 0;
}