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

int l;
int vis[305][305];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void print() {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cout << vis[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void solve() {
    cin >> l;
    for (int i = 0; i < l; i++) {
        fill(vis[i], vis[i] + l, 0);
    }
    int a, b, x, y; cin >> a >> b >> x >> y;
    queue<pi> q;
    q.push({a, b});
    vis[a][b] = 1;

    int cnt = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx, ny});
            // print();
        }
    }

    cout << vis[x][y] - 1 << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}