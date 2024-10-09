#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define X first
#define Y second
typedef pair<int, int> pi;
typedef vector<int> vi;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
const int N = 1005;
int n, m, st, en;
vector<pi> a[N];
int d[N];
int pre[N];

void solve() {
    cin >> n >> m;
    fill(d, d + n + 1, INF);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        a[u].push_back({w, v});
    }
    cin >> st >> en;
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    d[st] = 0;
    pq.push({0, st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : a[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[en] << nl;
    vi path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(all(path));
    cout << path.size() << nl;
    for (auto x : path) cout << x << " ";
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}