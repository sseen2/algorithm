#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef vector<int> vi;
typedef pair<int, int> pi;
const char nl = '\n';
const int N = 105;
int n;
int g[N][N];
int rs[N][N];
bool vis[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> g[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!g[i][j]) continue;

            fill(vis, vis + N, 0);
            queue<pi> q;
            q.push({i, j});
            rs[i][j] = 1;

            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                rs[cur.X][cur.Y] = 1;
                rs[i][cur.Y] = 1;
                
                for (int nxt = 1; nxt <= n; nxt++) {
                    if (vis[nxt] || !g[cur.Y][nxt]) continue;
                    q.push({cur.Y, nxt});
                    vis[nxt] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            cout << rs[i][j] << " ";
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}