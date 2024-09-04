#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 105;

int n, m, cnt;
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
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cnt++;
        for (auto nxt : g[cur]) {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
        }
    }

    cout << cnt - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}