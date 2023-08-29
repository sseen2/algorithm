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
int board[1002][1002];
bool vis[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    cin >> m >> n;
    bool nonZero = true;
    queue<pi> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) nonZero = false;
            if (board[i][j] == 1) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    if (nonZero) {
        cout << 0;
        return;
    }

    while (!q.empty()) {
        pi cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] == -1) continue;
            vis[nx][ny] = 1;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    int mx = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mx < board[i][j]) mx = board[i][j];
            if (!vis[i][j] && board[i][j] == 0) flag = true;
        }
    }

    if (flag) cout << -1;
    else cout << mx - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}