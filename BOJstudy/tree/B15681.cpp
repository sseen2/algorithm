#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 100005;
int n, r, q;
vi g[N];
int dp[N];

int dfs(int cur, int par) {
    if (dp[cur] != -1) return dp[cur];
    int cnt = 0;
    for (int nxt : g[cur]) {
        if (par == nxt) continue;
        cnt += dfs(nxt, cur) + 1;
    }
    dp[cur] = cnt;
    return cnt;
}

void solve() {
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fill(dp, dp + N, -1);
    dfs(r, 0);

    for (int i = 0; i < q; i++) {
        int u; cin >> u;
        cout << dp[u] + 1 << nl;
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}