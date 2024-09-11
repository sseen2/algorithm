#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 100005;
int n;
vi g[N];
int p[N];

void dfs (int cur) {
    for (int nxt : g[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

void bfs (int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : g[cur]) {
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);
    // dfs(1);
    for (int i = 2; i <= n; i++) cout << p[i] << nl;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}