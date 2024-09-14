#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int N = 1005;
int n, m, a, b, c;
vector<pi> g[N];    // 가중치, 다음 노드
int dist[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    for (int i = 0; i < m; i++) {
        int cnt = 0; cin >> a >> b;
        fill(dist, dist + N, 0);
        queue<int> q;
        q.push(a);
        dist[a] = 1;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == b) break;
            for (auto nxt : g[cur]) {
                if (dist[nxt.Y] > 0) continue;
                q.push(nxt.Y);
                dist[nxt.Y] = dist[cur] + nxt.X;
            }
        }
        cout << dist[b] - 1 << nl;
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}