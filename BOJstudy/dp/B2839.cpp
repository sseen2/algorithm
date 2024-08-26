#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int n;
int dp[5005];

void solve() {
    cin >> n;
    fill(dp, dp + n + 1, -1);
    dp[3] = 1; dp[5] = 1; dp[6] = 2;
    for (int i = 8; i <= n; i++) {
        if (dp[i - 3] == -1) { dp[i] = dp[i - 5] + 1; continue; }
        if (dp[i - 5] == -1) { dp[i] = dp[i - 3] + 1; continue; }
        dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
    }
    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}