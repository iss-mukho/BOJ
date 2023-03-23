#include <iostream>
using namespace std;
int counting[10001]; // ���������� ��� stack�� ����, ���������� ��� heap�� �����ϹǷ� �޸� ��뿡�� �����ο�
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
	for (int i = 0; i < 10001; i++) // counting�迭�� �����ؾ��ϹǷ�
		for (int j = 0; j < counting[i]; j++)
			cout << i << '\n';		
	return 0;
}
/* �޸� ��� ���� ®���� �ڵ�
#include <iostream>
using namespace std;
int main() {
	int N, * ary, *sorted, * counting;
	cin >> N;
	ary = new int[N]; // �Է¿�
	sorted = new int[N]; // ��¿�
	for (int i = 0; i < N; i++)
		cin >> ary[i];
	// 1. �ڷḦ Ž���ؼ� �� �ִ��� ���Ѵ�
	int max = ary[0];
	for (int i = 1; i < N; i++)
		if (max < ary[i])
			max = ary[i];
	// 2. k+1 ��ŭ�� ũ��� ��� �ڷᰡ 0���� �ʱ�ȭ�� �迭�� �����Ѵ�
	counting = new int[max+1]; // Counting Sort
	fill_n(counting, max + 1, 0);
	// 3. input�� ��� ���� n�� ���Ͽ� counting�� n�� �����ϴ� ���� +1�� ���ش�
	for (int i = 0; i < N; i++)
		++counting[ary[i]];
	// 4. counting[i] += counting[i-1]�� ��ȭ���� 1���� k�� ��ġ���� ���Ѵ�
	for (int i = 1; i < max + 1; i++)
		counting[i] += counting[i - 1];
	// 5. ���̰� counting[k]�� �迭�� �ϳ� �� �����Ѵ�
	int* ans;
	ans = new int[counting[max]];
	// 6. counting�� ary[0]�� �����ϴ� ���� ���Ҹ� ã�Ƽ� t�� ���´�
	// ���� ans�� t-1�� �����ϴ� ���� ary[0]�� �����ϰ�, counting�� ary[0]�� �����ϴ� ���� ���� -1 ���ش�
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