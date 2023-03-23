#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int cnt = 0;
	cin >> word;
	int s = word.size();

	bool* check = new bool[s];
	for (int i = 0; i < s; i++)
		check[i] = false;

	for (int i = 0; i < s-1; i++) {
		if (word.substr(i, 2) == "c=" || word.substr(i, 2) == "c-" || word.substr(i, 2) == "d-" || word.substr(i, 2) == "lj" || word.substr(i, 2) == "nj" || word.substr(i, 2) == "s=" || word.substr(i, 2) == "z=") {
			cnt += 1;
			check[i] = true;
			check[i + 1] = true;
			i++;
		}
		else if(word.substr(i, 2) == "dz")
			if (word[i + 2] == '=') {
				cnt += 1;
				check[i] = true;
				check[i + 1] = true;
				check[i + 2] = true;
				i += 2;
			}
	}
	for (int i = 0; i < s; i++) 
		if (check[i] == false)
			cnt++;
	cout << cnt << '\n';
	return 0;
}