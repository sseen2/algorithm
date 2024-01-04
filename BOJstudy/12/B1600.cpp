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

int k, h, w;
int board[205][205]; // h, w
int dist[205][205];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void print() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << dist[i][j] << " ";
        cout << nl;
    }
}

void solve() {
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
        }
    }

    queue<pi> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (dist[nx][ny] > -1 || board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    print();

    cout << dist[h - 1][w - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}