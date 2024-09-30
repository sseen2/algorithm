#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 105;
int n, m, sx, sy, ex, ey;
int board[N][N];
int dist[3][N][N];
queue<ti> q;
vector<vi> dx = {{-1, 1, 0, 0}, {-1, 1}, {0, 0}}, dy = {{0, 0, -1, 1}, {0, 0}, {-1, 1}};

void solve() {
    cin >> n >> m >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= n; i++) {
        fill(dist[0][i], dist[0][i] + m + 1, MX);
        fill(dist[1][i], dist[1][i] + m + 1, MX);
        fill(dist[2][i], dist[2][i] + m + 1, MX);
        for (int j = 1; j <= m; j++) 
            cin >> board[i][j];
    }

    q.push({sx, sy, 1});
    dist[0][sx][sy] = 0;
    while(!q.empty()) {
        int x, y, pmove;
        tie(x, y, pmove) = q.front(); q.pop();
        int cmove = pmove-- % 3;
        for (int dir = 0; dir < dx[cmove].size(); dir++) {
            int nx = x + dx[cmove][dir];
            int ny = y + dy[cmove][dir];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (dist[cmove][nx][ny] <= dist[pmove][x][y] + board[nx][ny] || board[nx][ny] == -1) continue;
            q.push({nx, ny, cmove + 1});
            dist[cmove][nx][ny] = dist[pmove][x][y] + board[nx][ny];
        }
    }

    int a = dist[0][ex][ey], b = dist[1][ex][ey], c = dist[2][ex][ey];
    if (a == MX && b == MX && c == MX) cout << -1;
    else cout << min(a, min(b , c));
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}