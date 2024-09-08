#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 105;

int n, m, rs;
vi g1[N];   // 가벼운 쪽으로
vi g2[N];   // 무거운 쪽으로
bool vis[N];

bool bfs(int i, vi g[N]) {
    fill(vis, vis + N, 0);
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : g[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
        }
    }
    if (cnt > (n - 1) / 2) return true;
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g1[a].push_back(b); // 가벼운 쪽으로
        g2[b].push_back(a); // 무거운 쪽으로
    }

    for (int i = 1; i <= n; i++) 
        if (bfs(i, g1) || bfs(i, g2)) rs++;

    cout << rs;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}