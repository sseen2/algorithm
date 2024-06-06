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
const int N = 95;

ll dp[N];

ll func(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    if (dp[k] != -1) return dp[k];

    dp[k] = func(k - 2) + func(k - 1);
    return dp[k];
}

void solve() {
    int n; cin >> n;
    fill(dp, dp + N, -1);
    cout << func(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}