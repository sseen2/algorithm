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

int n, m;
int board[305][305];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[305][305];
int cntarr[305][305];

void print() {
    cout << nl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
}

bool isZero() {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1;  j < m - 1; j++) {
            if (board[i][j] != 0) return true;
        }
    }

    return false;
}

int cntBFS() {
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
   
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && board[i][j] != 0) { 
                queue<pi> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || !board[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                cnt++;
            }
        }
    }

    // cout << cnt << nl;
    return cnt;
}

void IB() {
    for (int i = 0; i < n; i++) fill(cntarr[i], cntarr[i] + m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (board[nx][ny] == 0) cntarr[i][j] += 1; 
                }
            }
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (board[i][j] == 0 || board[i][j] < cntarr[i][j]) board[i][j] = 0;
            else board[i][j] -= cntarr[i][j];
        }
    }

    // cout << "cntarr" << nl;
    // for(int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << cntarr[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    // cout << nl;

    // print();
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    int cnt = 0;
    while(isZero()) {
        cnt++;
        IB();
        if (cntBFS() >= 2) {
            cout << cnt; return;
        }
    }

    cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}