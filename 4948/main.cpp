#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int check[246913];
	fill_n(check, 246913, 1);
	check[0] = 0;
	check[1] = 0;
	while (true) {
		int n, count = 0;
		cin >> n;
		if (!n)
			break;
		for (int i = 2; i <= n * 2; i++) {
			if (check[i] == 0)
				continue;
			for (int j = 1; i*j <= n*2; j++)
				if (i != i*j)
					check[i*j] = 0;
		}
		for (int i = n + 1; i <= n * 2; i++)
			if (check[i] == 1)
				count++;
		cout << count << '\n';
	}
	return 0;
}