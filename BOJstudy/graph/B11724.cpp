#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 1005;

int n, m, cnt; // 정점, 간선
vi g[N];
bool vis[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        q.push(i);
        vis[i] = true;
        cnt++;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nxt : g[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}