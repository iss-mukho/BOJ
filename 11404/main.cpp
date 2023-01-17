#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1000000000001; // �־��� ���: 100 * 100000 * 100000 = 1��(int�� �ִ밪�� 21�� �ʰ�)
const int MAX = 100;
int n, m, a, b, c;
ll city[MAX + 1][MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// �Է�1
	cin >> n;
	cin >> m;

	// �ʱ�ȭ1
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			city[i][j] = INF;
	// �ʱ�ȭ2: ���� ���ÿ� ���� ���ð� ���� ���� ����.
	for (int i = 1; i <= n; ++i)
		city[i][i] = 0;

	// �Է�2
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		// ���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� �ϳ��� �ƴ� �� �ִ�.
		if(city[a][b] > c)
			city[a][b] = c;
	}

	// �÷��̵�-����
	for (int x = 1; x <= n; ++x)
		for (int s = 1; s <= n; ++s)
			for (int e = 1; e <= n; ++e)
				city[s][e] = min(city[s][e], city[s][x] + city[x][e]);

	// ���
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (city[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << city[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}