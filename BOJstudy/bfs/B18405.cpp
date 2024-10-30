#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 205;
int n, k, s, ex, ey;
int board[N][N];
int t[N][N];
int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};

void solve() {
    cin >> n >> k;
    vector<tuple<int, int, int>> v;
    for (int i = 1; i <= n; i++) {
        fill(t[i], t[i] + n + 1, MX);
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                v.push_back({board[i][j], i, j});
                t[i][j] = 0;
            }
        }
    }
    cin >> s >> ex >> ey;

    sort(all(v));
    queue<pi> q;
    for (int i = 0; i < v.size(); i++) {
        int x, y, z; tie(z, x, y) = v[i];
        q.push({x, y});
    }

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (board[nx][ny] != 0) continue;
            q.push({nx, ny});
            board[nx][ny] = board[cur.X][cur.Y];
            t[nx][ny] = t[cur.X][cur.Y] + 1;
        }
    }

    if (t[ex][ey] <= s) cout << board[ex][ey];
    else cout << 0;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}