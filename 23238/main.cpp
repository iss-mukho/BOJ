#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int N, Q, sq, ans[MAXN], a[MAXN];
struct query {
    int l, r, idx;
} q[MAXN];
bool cmp(query x, query y) {
    if (x.l / sq != y.l / sq) {
        return x.l < y.l;
    }
    return x.r < y.r;
}
map<int, int> cnt;
void add(int x, int& freq_val, int& freq, int& max_val) {
    cnt[a[x]]++;
    if (cnt[a[x]] == freq_val) {
        max_val = max(max_val, a[x]);
    }
    else if (cnt[a[x]] > freq_val) {
        freq_val = cnt[a[x]];
        freq = 1;
        max_val = a[x];
    }
}
void del(int x, int& freq_val, int& freq, int& max_val) {
    cnt[a[x]]--;
    if (cnt[a[x]] == freq_val - 1) {
        freq--;
    }
    else if (cnt[a[x]] == freq_val) {
        max_val = max(max_val, a[x]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    sq = sqrt(N);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= Q; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }
    sort(q + 1, q + Q + 1, cmp);
    int l = 1, r = 0;
    int freq = 0, freq_val = 0, max_val = 0;
    for (int i = 1; i <= Q; i++) {
        while (l < q[i].l) {
            del(l, freq_val, freq, max_val);
            l++;
        }
        while (l > q[i].l) {
            l--;
            add(l, freq_val, freq, max_val);
        }
        while (r < q[i].r) {
            r++;
            add(r, freq_val, freq, max_val);
        }
        while (r > q[i].r) {
            del(r, freq_val, freq, max_val);
            r--;
        }
        if (freq == 1) {
            ans[q[i].idx] = max_val;
        }
        else {
            ans[q[i].idx] = max_val;
        }
    }
    for (int i = 1; i <= Q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}