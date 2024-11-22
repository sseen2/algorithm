#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 1005;

int n, mn = INT_MAX;
int p[N];
int dp[N];

int func(int k) {
    if (k > n + 1) return MX;
    if (k == n + 1) return 0;
    if (dp[k] != -1) return dp[k];

    int rs = MX;
    for (int i = 1; i <= n; i++)
        rs = min(rs, func(k + i) + p[i]);
    dp[k] = rs;
    return rs;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    fill(dp, dp + N + 1, -1);
    func(0);
    
    cout << dp[1];
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}