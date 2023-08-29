#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second

int n, m;
int board[102][102];
int vis[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    vis[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        bool flag = false;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx, ny});
            if (nx == n - 1 && ny == m - 1) flag = true;
        }
        if (flag) break;
    }

    cout << vis[n-1][m-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}