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
const int N = 20;

int n;
int t[N];
int p[N];
int dp[N];

int func(int k) {
    if (k == n) return 0;
    if (dp[k] != -1) return dp[k];

    int result = func(k + 1);
    if (t[k] + k <= n) result = max(result, func(k + t[k]) + p[k]);
    dp[k] = result;
    return result;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
    fill(dp, dp + N, -1);
    cout << func(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}