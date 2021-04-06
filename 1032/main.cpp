#include <iostream>
#include <string>
using namespace std;
string input[50];
int main() {
	int N, i, j, size;
	string temp;
	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> input[i];
	temp = input[0];
	size = temp.length();
	for (i = 1; i < N; ++i) 
		for (j = 0; j < size; ++j) 
			if (temp[j] != input[i][j])
				temp[j] = '?';
	cout << temp << '\n';
	return 0;
}