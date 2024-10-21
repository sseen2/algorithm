#include <bits/stdc++.h>
using namespace std;
#define all(x) x.rbegin(), x.rend()
typedef vector<int> vi;
const char nl = '\n';
const int N = 100'005;
int n, m, r, seq = 0;
vi g[N];
bool d[N];
int rs[N];

void dfs(int cur) {
    d[cur] = 1;
    rs[cur] = ++seq;
    for (auto nxt : g[cur]) {
        if (d[nxt]) continue;
        dfs(nxt);
    }
}

void solve() {
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) sort(all(g[i]));

    dfs(r);
    for (int i = 1; i <= n; i++) cout << rs[i] << nl;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}