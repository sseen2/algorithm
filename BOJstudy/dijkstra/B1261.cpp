#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 105;
int n, m;
int board[N][N];
vector<ti> g[N][N];
int d[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++)
            board[i][j] = s[j - 1] - '0';
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                g[i][j].push_back({board[nx][ny], nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; i++) fill(d[i], d[i] + m + 1, MX);

    priority_queue<ti, vector<ti>, greater<ti>> pq;
    d[1][1] = 0;
    pq.push({0, 1, 1});
    while(!pq.empty()) {
        int w, x, y, nx, ny, nw;
        tie(w, x, y) = pq.top(); pq.pop();
        if (w != d[x][y]) continue;
        for (auto nxt : g[x][y]) {
            tie(nw, nx, ny) = nxt;
            if (d[nx][ny] <= d[x][y] + nw) continue;
            d[nx][ny] = d[x][y] + nw;
            pq.push({d[nx][ny], nx, ny});
        }
    }

    cout << d[n][m];
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}