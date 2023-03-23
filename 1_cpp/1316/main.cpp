#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		bool alphabet[26] = { false, };
		bool isGroup = false;

		for (int i = 0; i < word.size(); i++) {
			char temp = word[i];
			if (alphabet[(int)temp - 97] == true) {
				isGroup = false;
				break;
			}
			else
				alphabet[(int)temp - 97] = true;
			for (int j = i + 1; j < word.size(); j++) {
				if (temp == word[j])
					i++;
				else
					break;
			}
			isGroup = true;
		}
		if (isGroup)
			count++;
	}
	cout << count << '\n';
	return 0;
}