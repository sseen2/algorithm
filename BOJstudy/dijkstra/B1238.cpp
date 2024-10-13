#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 1005;
int n, m, x, mx;
vector<pi> g[N];
int xtoh[N];    // x에서 집으로 가는 최단거리
int htox[N][N];    // 집에서 x로 가는 최단거리

void solve() {
    cin >> n >> m >> x;
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    fill(xtoh, xtoh + n + 1, MX);

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    xtoh[x] = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != xtoh[cur.Y]) continue;
        for (auto nxt : g[cur.Y]) {
            if (xtoh[nxt.Y] <= xtoh[cur.Y] + nxt.X) continue;
            xtoh[nxt.Y] = xtoh[cur.Y] + nxt.X;
            pq.push({xtoh[nxt.Y], nxt.Y});
        }
    }

    for (int i = 1; i <= n; i++) {
        fill(htox[i], htox[i] + n + 1, MX);
        htox[i][i] = 0;
        pq.push({0, i});
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (cur.X != htox[i][cur.Y]) continue;
            for (auto nxt : g[cur.Y]) {
                if (htox[i][nxt.Y] <= htox[i][cur.Y] + nxt.X) continue;
                htox[i][nxt.Y] = htox[i][cur.Y] + nxt.X;
                pq.push({htox[i][nxt.Y], nxt.Y});
            }
        }
    }

    for (int i = 1; i <= n; i++) mx = max(mx, xtoh[i] + htox[i][x]);
    cout << mx;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}