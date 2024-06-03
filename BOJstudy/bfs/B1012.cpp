#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int n, m;
int board[55][55];
bool vis[55][55];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    cin >> n >> m;
    int k; cin >> k;
    for (int i = 0; i < n; i++) {
        fill(board[i], board[i] + n, 0);
        fill(vis[i], vis[i] + n, false);
    }

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        board[x][y] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !vis[i][j]) {
                queue<pi> q;
                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                cnt++;
            }
        }
    }

    cout << cnt << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}