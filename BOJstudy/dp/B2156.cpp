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
const int N = 10005;

int n;
int w[N];
int dp[4][N];

int func(int cnt, int k) {
    if (k == n) return 0;
    if (dp[cnt][k] != -1) return dp[cnt][k];

    int result = func(0, k + 1);
    if (cnt < 2) result = max(result, func(cnt + 1, k + 1) + w[k]);
    dp[cnt][k] = result;
    return result;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < 4; i++) fill(dp[i], dp[i] + N, -1);
    cout << func(0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}