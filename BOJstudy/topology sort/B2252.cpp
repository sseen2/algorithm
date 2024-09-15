#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 32005;
int n, m;
vi g[N];
int deg[N];
vi rs;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        deg[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        rs.push_back(cur);
        for (int nxt : g[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    for (auto x : rs) cout << x << " ";
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);solve();
}