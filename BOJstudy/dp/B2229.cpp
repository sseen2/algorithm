#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int N = 1005;
int n;
int stu[N];
int dp[N];

int func(int k) {
    if (k == n) return 0;
    if (dp[k] != -1) return dp[k];
    
    int rs = func(k + 1),
        mn = stu[k], mx = stu[k];
    for (int i = k; i < n; i++) {
        mn = min(mn, stu[i]), mx = max(mx, stu[i]);
        rs = max(rs, func(i + 1) + mx - mn);
    }

    dp[k] = rs;
    return rs;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> stu[i];
    fill(dp, dp + n, -1);

    func(0);
    cout << dp[0];
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}