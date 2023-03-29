// 백준 1620: 나는야 포켓몬 마스터 이다솜(실버 IV), https://www.acmicpc.net/problem/1620
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> hashMap;
int N, M;
string name;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> name;
        hashMap.insert(make_pair(name, to_string(i)));
        hashMap.insert(make_pair(to_string(i), name));
    }

    for(int i=0; i<M; ++i){
        cin >> name;
        cout << hashMap[name] << '\n';
    }

    return 0;
}