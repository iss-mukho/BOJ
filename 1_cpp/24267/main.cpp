// 백준 24267: 알고리즘 수업 - 알고리즘의 수행 시간 6(브론즈 II), https://www.acmicpc.net/problem/24267
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);
	printf("%lld\n%d\n", n*(n-1)*(n-2)/6, 3);
	return 0;
}