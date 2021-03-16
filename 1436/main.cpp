#include <iostream>
#include <string>
using namespace std;
int main() {
	int N, cnt = 0;
	cin >> N;
	int i = 666;
	while(true) {
		string temp = to_string(i);
		if (temp.find("666") != -1) {
			cnt++;
			if (N == cnt)
				break;
		}
		i++;
	}
	cout << i << '\n';
	return 0;
}