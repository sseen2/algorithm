#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 1005;
int n, m, st, en;
vector<pi> g[N];
int d[N];

void solve() {
    cin >> n >> m;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    cin >> st >> en;
    fill(d, d + n + 1, MX);

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != d[cur.Y]) continue;
        for (auto nxt : g[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    cout << d[en];
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}