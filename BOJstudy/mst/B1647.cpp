#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int N = 100005;
int n, m, a, b, c, cost, cnt, rs, mx;
vector<pi> g[N];
bool chk[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    chk[1] = 1;
    for (auto nxt : g[1]) pq.push({nxt.X, nxt.Y});
    while (cnt < n - 1) {
        tie(cost, a) = pq.top(); pq.pop();
        if (chk[a]) continue;
        cnt++;
        chk[a] = 1;
        rs += cost;
        mx = max(mx, cost);
        for (auto nxt : g[a])
            if (!chk[nxt.Y]) pq.push({nxt.X, nxt.Y});
    }
    cout << rs - mx;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}