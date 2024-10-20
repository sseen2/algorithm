#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 8'000'005;
vector<bool> p(N + 1, 1);

void solve() {
    int k; cin >> k;
    p[1] = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (!p[i]) continue;
        for (int j = i * i; j <= N; j += i) p[j] = 0;
    }

    int rs = 0, cnt = 0, idx = 1;
    while (1) {
        if (p[idx]) cnt++;
        if (cnt == k) { rs = idx; break; }
        idx++;
    }

    cout << rs;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}