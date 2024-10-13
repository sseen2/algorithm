#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
typedef pair<int, int> pi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 805;
int n, e, v1, v2;
vector<pi> g[N];
ll d[N][N];

void solve() {
    cin >> n >> e;
    while (e--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    cin >> v1 >> v2;

    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, MX);   
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        d[i][i] = 0;
        pq.push({0, i});
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (cur.X != d[i][cur.Y]) continue;
            for (auto nxt : g[cur.Y]) {
                if (d[i][nxt.Y] <= d[i][cur.Y] + nxt.X) continue;
                d[i][nxt.Y] = d[i][cur.Y] + nxt.X;
                pq.push({d[i][nxt.Y], nxt.Y});
            }
        }
    }

    ll rs = min(d[1][v1] + d[v1][v2] + d[v2][n], d[1][v2] + d[v2][v1] + d[v1][n]);
    if (rs >= MX) cout << -1;
    else cout << rs;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}