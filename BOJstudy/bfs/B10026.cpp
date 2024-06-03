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

int n;
char board[105][105];
bool vis1[105][105];
bool vis2[105][105];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print(bool vis[105][105]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vis[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void BFS2(int i, int j, bool vis[105][105]) {
    queue<pi> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[nx][ny] == 'B') continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    // print(vis2);
}

void BFS1(int i, int j, bool vis[105][105]) {
    queue<pi> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || board[cur.X][cur.Y] != board[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    // print(vis1);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j];
        }
    }

    int cnt1 = 0, cnt2 = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R' && !vis1[i][j]) {
                BFS1(i, j, vis1);
                cnt1++;
            }
            else if (board[i][j] == 'G' && !vis1[i][j]) {
                BFS1(i, j, vis1);
                cnt1++;
            }
            else if (board[i][j] == 'B' && !vis1[i][j]) {
                BFS1(i, j, vis1);
                cnt1++;
                cnt2++;
            }

            if ((board[i][j] == 'R' || board[i][j] == 'G') && !vis2[i][j]) {
                BFS2(i, j, vis2);
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--)
        solve();
}