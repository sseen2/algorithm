#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int n;
int dp[12];

int func(int k) {
    if (dp[k] != -1) return dp[k];
    dp[k] = func(k - 3) + func(k - 2) + func(k - 1);
    return dp[k];
}

void solve() {
    cin >> n;
    fill(dp, dp + 12, -1);
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    cout << func(n) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}