#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int kor, eng, mat;
};
bool cmp(Student a, Student b);
vector<Student> v(100000);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, i;
	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].mat;

	sort(v.begin(), v.begin() + N, cmp);
	for (i = 0; i < N; ++i) 
		cout <<v[i].name << '\n';
	return 0;
}

bool cmp(Student a, Student b) {
	if (a.kor > b.kor)
		return true;
	else if (a.kor == b.kor) {
		if (a.eng < b.eng)
			return true;
		else if (a.eng == b.eng) {
			if (a.mat > b.mat)
				return true;
			else if (a.mat == b.mat) {
				if (a.name < b.name)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}