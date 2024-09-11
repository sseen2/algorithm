#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 505;
int n, m;
vi g[N];
int p[N];

bool bfs(int root) {
    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : g[cur]) {
            if (p[cur] == nxt) continue;
            if (p[nxt] != 0) return false;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    return true;
}

void solve() {
    for (int i = 1; i <= n; i++) g[i].clear();
    fill(p, p + N, 0);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] != 0) continue;
        if (bfs(i)) cnt++;
    }

    if (cnt == 0) cout << "No trees." << nl;
    else if (cnt == 1) cout << "There is one tree." << nl;
    else cout << "A forest of " << cnt << " trees." << nl;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cout << "Case " << t++ << ": ";
        solve();
    }
}