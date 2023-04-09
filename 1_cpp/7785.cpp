// 백준 7785: 회사에 있는 사람(실버 V), https://www.acmicpc.net/problem/7785
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

typedef pair<string, bool> psb;

int N;
char name[6], onoff[6];
map<string, bool, greater<string>> logs;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N; ++i){
        cin >> name >> onoff;
        if(strcmp(onoff, "leave") == 0){
            if(logs.find(name) != logs.end()) logs.erase(name);
            continue;
        }
        logs.insert(psb(name, true));
    }

    for(auto log: logs)
        cout << log.first << '\n';

    return 0;
}
