#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 100000;
const ll INF = 2000000001;

int N, l, h;
ll numbers[MAX], num1, num2, diff = INF;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%lld", &numbers[i]);

	l = 0, h = N - 1;
	while (l < h) {
		ll a = numbers[l], b = numbers[h];
		ll temp = a + b;
		ll curDiff = abs(temp);

		if (curDiff <= diff) {
			diff = curDiff;
			num1 = a, num2 = b;
		}

		if (temp < 0) ++l;
		else --h;
	}

	printf("%lld %lld\n", num1, num2);
	
	return 0;
}