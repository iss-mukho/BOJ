// 백준 5597: 과제 안 내신 분..?(브론즈 V), https://www.acmicpc.net/problem/5597
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 30;

int id;
bool submit[MAX+1];

int main(){
    for(int i=0; i<MAX-2; ++i){
        scanf("%d", &id);
        submit[id] = true;
    }
    
    for(int i=1; i<=MAX; ++i){
        if(submit[i]) continue;
        printf("%d\n", i);
    }

    return 0;
}
