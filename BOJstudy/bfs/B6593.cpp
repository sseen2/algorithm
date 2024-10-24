#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int N = 35;
int l, r, c, stX, stY, stZ, enX, enY, enZ;
char board[N][N][N];
int dx[] = {1, 0, -1, 0, 0, 0},
    dy[] = {0, 1, 0, -1, 0, 0},
    dz[] = {0, 0, 0, 0, 1, -1};

void solve() {
    int dist[N][N][N];
    for (int h = 0; h < l; h++) {
        for (int i = 0; i < r; i++) {
            string s; cin >> s;
            fill(dist[h][i], dist[h][i] + c, -1);
            for (int j = 0; j < c; j++) {
                if (s[j] == 'S') {
                    stZ = h;
                    stX = i;
                    stY = j;
                }
                if (s[j] == 'E') {
                    enZ = h;
                    enX = i;
                    enY = j;
                }
                board[h][i][j] = s[j];
            }
        }
    }

    queue<ti> q;
    q.push({stZ, stX, stY});
    dist[stZ][stX][stY] = 0;
    while(!q.empty()) {
        int x, y, z;
        tie(z, x, y) = q.front(); q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (dist[nz][nx][ny] != -1 || board[nz][nx][ny] == '#') continue;
            q.push({nz, nx, ny});
            dist[nz][nx][ny] = dist[z][x][y] + 1;
        }
    }

    if (dist[enZ][enX][enY] == -1) cout << "Trapped!" << nl;
    else cout << "Escaped in " << dist[enZ][enX][enY] << " minute(s)." << nl;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> l >> r >> c) {
        if (l == 0 && r == 0 && c == 0) break;
        solve();
    }
}