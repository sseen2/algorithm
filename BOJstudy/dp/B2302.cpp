#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 45;
const int M = 45;

int n, m; 
int dp[N];

void solve() {
    cin >> n >> m;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    ll rs = 1, vip = 0, start = 0;
    for (int i = 0; i < m; i++) {
        cin >> vip;
        rs *= dp[vip - start - 1];
        start = vip;
    }
    rs *= dp[n - start];

    cout << rs;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
