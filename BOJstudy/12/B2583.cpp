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

int m, n, k; 
int board[105][105];
int vis[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void pb() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void pv() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << vis[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void solve() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int fx, fy, cx, cy;
        cin >> fy >> fx >> cy >> cx;
        for (int x = fx; x < cx; x++) {
            for (int y = fy; y < cy; y++) {
                board[x][y] = 1;
            }
        }
    }

    vi v;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] || vis[i][j]) continue;
            queue<pi> q;
            q.push({i, j});
            vis[i][j] = 1;
            int area = 1;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] || vis[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    area++;
                }
            }
            v.push_back(area);
        }
    }
    sort(all(v));

    cout << v.size() << nl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}