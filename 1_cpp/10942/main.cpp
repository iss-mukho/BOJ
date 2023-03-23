/* 백준 10942: 팰린드롬?(골드 IV), https://www.acmicpc.net/problem/10942
* 시도 1: 문자열 뒤집기를 이용한 비교 -> 시간 초과
* 시도 2: 투 포인터를 이용한 비교 -> 틀렸습니다
* 시도 3: 숫자가 한 자리 수가 아니었음, 문자열에서 벡터로 변경 -> 시간 초과
* 시도 4: HELP- 다이나믹 프로그래밍?
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
	// 입력: 수열의 크기
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &number[i]); // 입력: 수열
		dp[i][i] = true; // 초기화
	}

	// 연속된 수 초기화
	for (int i = 1; i < N; ++i)
		if (number[i] == number[i + 1])
			dp[i][i + 1] = true;

	// DP 갱신: 거꾸로
	for (int i = N - 1; i > 0; --i)
		for (int j = i + 2; j <= N; ++j)
			if (number[i] == number[j] && dp[i + 1][j - 1]) // [S:E]가 팰린드롬이려면 [S+1:E-1]도 팰린드롬이어야 한다
				dp[i][j] = true;
	
	// 입력: 질문의 개수
	scanf("%d", &M);

	while (M--) {
		scanf("%d %d", &S, &E); // 입력: 질문
		printf("%d\n", dp[S][E]); // 출력
	}

	return 0;
}