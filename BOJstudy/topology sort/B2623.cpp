#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int N = 1005;
int n, m;
vi g[N];
int deg[N];
vi rs;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        int a[num]; cin >> a[0];
        for (int j = 1; j < num; j++) {
            cin >> a[j];
            g[a[j - 1]].push_back(a[j]);
            deg[a[j]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        rs.push_back(cur);
        for (auto nxt : g[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    if (rs.size() != n) cout << 0;
    else 
        for (auto x : rs) cout << x << nl;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}