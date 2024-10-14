#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
typedef pair<ll, int> pi;
const char nl = '\n';
const ll MX = LLONG_MAX;
const int N = 100'005;
int n, m, k;
vector<pi> g[N];
ll d[N];

void solve() {
    cin >> n >> m >> k;
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        g[v].push_back({c, u});
    }

    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        g[0].push_back({0, a});
    }

    fill(d, d + n + 1, MX);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != d[cur.Y]) continue;
        for (auto nxt : g[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    ll rs = 0, rsMX = 0;
    for (int i = 0; i <= n; i++) {
        if (rsMX < d[i]) {
            rs = i;
            rsMX = d[i];
        }
    }

    cout << rs << nl << rsMX;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}