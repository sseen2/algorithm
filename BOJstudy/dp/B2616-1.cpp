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
const int N = 50005;

int n, m;
int t[N];
int dp[3][N];

int func(int u, int k) {
    if (k == n || u == 3) return 0;
    if (dp[u][k] != -1) return dp[u][k];

    int result = func(u, k + 1);
    int sum = 0;
    for (int i = k; i < k + m; i++) {
        if (i >= n) {
            dp[u][k] = result;
            return result;
        }
        sum += t[i];
    }
    result = max(result, func(u + 1, k + m) + sum);
    dp[u][k] = result;
    return result;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    cin >> m;
    for (int i = 0; i < 3; i++) fill(dp[i], dp[i] + N, -1);

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