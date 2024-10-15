#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
typedef pair<ll, ll> pl;
const char nl = '\n';
const ll MX = LLONG_MAX;
const int N = 100'005;
ll n, m, a, b, c;
vector<pl> g[N];

bool Check(ll mid) {
    ll d[N];
    fill(d, d + n + 1, MX);
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    d[a] = 0;
    pq.push({0, a});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != d[cur.Y]) continue;
        for (auto nxt : g[cur.Y]) {
            if (nxt.X > mid) continue;
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    return d[b] <= c;
}

void solve() {
    cin >> n >> m >> a >> b >> c;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    ll st = 0, en = c + 1;
    while (st + 1 < en) {
        ll mid = (st + en) / 2;
        if (Check(mid)) en = mid;
        else st = mid;
    }

    if (en == c + 1) cout << -1;
    else cout << en;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}