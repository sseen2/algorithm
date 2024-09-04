#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
typedef vector<int> vi;

const char nl = '\n';
const int N = 505;
int n, m, cnt, rs;
vi g[N];
bool vis[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<pi> q;
    q.push({1, 1});
    vis[1] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        cnt++;
        for (auto nxt : g[cur.X]) {
            if (vis[nxt]) continue;
            if (cur.Y >= 2) continue;
            q.push({nxt, cnt});
            vis[nxt] = 1;
            rs++;
        }
    }

    cout << rs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}