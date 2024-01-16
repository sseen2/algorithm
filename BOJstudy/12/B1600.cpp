#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int k, w, h;
int board[205][205];
int dist[205][205][35];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int hx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void print() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << dist[i][j][0] << " ";
        }
        cout << nl;
    }
    cout << nl;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << dist[i][j][1] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void solve() {
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            fill(dist[i][j], dist[i][j] + k + 1, -1);
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({0, 0, k});
    dist[0][0][k] = 0;
    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
        if (z > 0) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = x + hx[dir];
                int ny = y + hy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == 1 || dist[nx][ny][z - 1] != -1) continue;
                q.push({nx, ny, z - 1});
                dist[nx][ny][z - 1] = dist[x][y][z] + 1;
            }
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == 1 || dist[nx][ny][z] != -1) continue;
            q.push({nx, ny, z});
            dist[nx][ny][z] = dist[x][y][z] + 1;
        }
    }
    int a = dist[h - 1][w - 1][0], b = dist[h - 1][w - 1][1];

    if (a != -1) cout << a;
    else cout << b;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}