/**
 * 백준 23238: Best Friend(다이아몬드 V), https://www.acmicpc.net/problem/23238
 * Offline Query + Sqrt Decomposition + Mo's Algorithm
 */
#include <bits/stdc++.h> // need setting
using namespace std;

const int MAX = 100001;
const int sn = 316;
struct S {
	int x, ox, num;
} a[MAX]; // 각 위치의 원래 값 저장
bool cmpX(S p,S q) {
    return p.ox < q.ox;
}
bool cmpNum(S p, S q) {
    return p.num < q.num;
}
struct Q {
	int x, y, num;
} b[MAX];
bool cmp_Q(Q p, Q q) {
	return (p.x/sn == q.x/sn) ? p.y < q.y : p.x/sn < q.x/sn;
}

int n, m, gn, s, e, p, q, mx;
int countArray[MAX], countArrayInQuery[MAX], ans[MAX], arr[MAX], bNum[sn+1], num[sn+1][MAX];

// mo's algorithm
void up(int idx) {
	int idx2 = idx / sn;
	if(countArray[idx] == bNum[idx2]) ++bNum[idx2];
	--num[idx2][countArray[idx]++];
	++num[idx2][countArray[idx]];
}
void down(int idx) {
	int idx2 = idx / sn;
	--num[idx2][countArray[idx]--];
	++num[idx2][countArray[idx]];
	if(num[idx2][bNum[idx2]] == 0) --bNum[idx2];
}

// 구간에서 가장 많이 등장한 수 찾기
int getAnswer() {
	int nIdx = gn-1, nMax = bNum[nIdx];
	for(int i = gn-2; i > -1; --i)
		if(nMax<bNum[i]) nMax = bNum[i], nIdx = i;

	int current = -1, answer = -1;
	for(int i = 0, j = sn * nIdx; i < sn && j < n; ++i, ++j)
		if(current <= countArray[j]) current = countArray[j], answer = j;

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 입력1
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].ox;
		a[i].num = i;
	}
	sort(a, a+n, cmpX);

	a[0].x = 0; countArrayInQuery[0] = a[0].ox;
	for(int i = 1; i < n; ++i) {
		a[i].x = a[i-1].x + (a[i-1].ox != a[i].ox);
		countArrayInQuery[a[i].x] = a[i].ox;
	}

	mx = a[n-1].x;
	gn = mx / sn + 1;
	sort(a, a+n, cmpNum);
	for(int i = 0; i < n; ++i)
		arr[i] = a[i].x;
	
	for(int i = 0; i < m; ++i) {
		cin >> p >> q;
		b[i] = {--p, --q, i}; // new
	}

	// 처리
	sort(b, b+m, cmp_Q); // x 좌표 기준으로 정렬
	s = 0, e = -1;
	for(int i = 0; i < m; ++i) {
		while(e<b[i].y) up(arr[++e]);
		while(s>b[i].x) up(arr[--s]);
		while(e>b[i].y) down(arr[e--]);
		while(s<b[i].x) down(arr[s++]);
		ans[b[i].num] = getAnswer();
	}

	// 출력
	for(int i = 0; i < m; ++i)
		cout << countArrayInQuery[ans[i]] << '\n';

	return 0;
}