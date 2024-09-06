#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int V = 20'005;

int v, e; 
int vis[V];

void solve() {
    cin >> v >> e;
    vi g[V];
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(vis, vis + V, -1);

    for (int i = 1; i <= v; i++) {
        if (vis[i] != -1) continue;
        queue<int> q;
        q.push(i);
        vis[i] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nxt : g[cur]) {
                if (vis[nxt] != -1) continue;
                q.push(nxt);
                vis[nxt] = !vis[cur];
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= v; i++) 
        for (auto nxt : g[i]) 
            if (vis[i] == vis[nxt]) { flag = 1; break; }

    if (flag) cout << "NO" << nl;
    else cout << "YES" << nl;
}

// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}