#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
const int V = 20005;
int v, e, st;
vector<pi> adj[V];  // 비용, 정점 번호
int d[V];

void solve() {
    cin >> v >> e >> st;
    fill(d, d + v + 1, INF);
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[st] = 0;
    pq.push({d[st], st});   // {0, 시작점}
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    for (int i = 1; i <= v; i++)
        if (d[i] == INF) cout << "INF" << nl;
        else cout << d[i] << nl;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}