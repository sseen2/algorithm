#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second

int n, m; 
int board[500][500];
bool vis[500][500];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    cin >> n >> m;;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0, max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !vis[i][j]) {
                int size = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    size++;
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
                if (max < size) max = size;
            }
        }
    }

    cout << cnt << "\n" << max;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}