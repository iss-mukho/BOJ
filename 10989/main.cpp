#include <iostream>
using namespace std;
int counting[10001]; // 지역변수의 경우 stack에 저장, 전역변수의 경우 heap에 저장하므로 메모리 사용에서 자유로움
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		++counting[temp];
	}
	for (int i = 0; i < 10001; i++) // counting배열에 접근해야하므로
		for (int j = 0; j < counting[i]; j++)
			cout << i << '\n';		
	return 0;
}
/* 메모리 상관 없이 짰었던 코드
#include <iostream>
using namespace std;
int main() {
	int N, * ary, *sorted, * counting;
	cin >> N;
	ary = new int[N]; // 입력용
	sorted = new int[N]; // 출력용
	for (int i = 0; i < N; i++)
		cin >> ary[i];
	// 1. 자료를 탐색해서 그 최댓값을 구한다
	int max = ary[0];
	for (int i = 1; i < N; i++)
		if (max < ary[i])
			max = ary[i];
	// 2. k+1 만큼의 크기로 모든 자료가 0으로 초기화된 배열을 생성한다
	counting = new int[max+1]; // Counting Sort
	fill_n(counting, max + 1, 0);
	// 3. input의 모든 원소 n에 대하여 counting의 n에 대응하는 곳에 +1을 해준다
	for (int i = 0; i < N; i++)
		++counting[ary[i]];
	// 4. counting[i] += counting[i-1]의 점화식을 1부터 k의 위치까지 행한다
	for (int i = 1; i < max + 1; i++)
		counting[i] += counting[i - 1];
	// 5. 길이가 counting[k]인 배열을 하나 더 생성한다
	int* ans;
	ans = new int[counting[max]];
	// 6. counting의 ary[0]에 대응하는 곳의 원소를 찾아서 t로 놓는다
	// 이제 ans의 t-1에 대응하는 곳에 ary[0]을 저장하고, counting의 ary[0]에 대응하는 곳의 값은 -1 해준다
	for (int i = 0; i < N; i++) {
		int t = counting[ary[i]];
		ans[t - 1] = ary[i];
		--counting[ary[i]];
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << '\n';
	return 0;
}
*/