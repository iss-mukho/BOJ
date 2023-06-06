// 백준 23235: The Fastest Sorting Algorithm In The World(브론즈 V), https://www.acmicpc.net/problem/23235
#include <iostream>
#include <string>
using namespace std;

int main() {
	int i = 1;
	while (true) {
		string temp;
		getline(cin, temp);
		if (temp == "0") break;
		cout << "Case " << i++ << ": Sorting... done!\n";
	}

	return 0;
}
