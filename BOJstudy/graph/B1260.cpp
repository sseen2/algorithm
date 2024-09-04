#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 1005;

int n, m, v;
vi g[N];
bool visB[N];
bool visD[N];

void dfs(int cur) {
    visD[cur] = true;
    cout << cur << " ";
    for (auto nxt : g[cur]) {
        if (visD[nxt]) continue;
        dfs(nxt);
    }
}

void bfs() {
    queue<int> q;
    q.push(v);
    visB[v] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for (auto nxt : g[cur]) {
            if (visB[nxt]) continue;
            q.push(nxt);
            visB[nxt] = true;
        }
    }
}

void solve() {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());

    dfs(v);
    cout << nl;
    bfs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    solve();
}