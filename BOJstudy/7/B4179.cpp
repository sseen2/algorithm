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

char maze[1002][1002];
int vis[1002][1002];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int r, c;

void print() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << vis[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void solve() {
    cin >> r >> c;
    queue<pi> jq;   // 지훈이의 이동
    queue<pi> fq;   // 불의 이동
    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++) {
            maze[i][j] = s[j];
            if (maze[i][j] == 'J') {
                jq.push({i, j});
                vis[i][j] = 1;  
            } 
            else if (maze[i][j] == 'F') {
                fq.push({i, j});
                vis[i][j] = 1;
            }
            else if (maze[i][j] == '#') vis[i][j] = -1;
        }
    }

    while (!fq.empty()) {
        auto cur = fq.front(); fq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (vis[nx][ny] != 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            fq.push({nx, ny});
        }
    }

    while (!jq.empty()) {
        auto cur = jq.front(); jq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << vis[cur.X][cur.Y];
                return;
            }
            if (vis[nx][ny] != 0 && vis[nx][ny] <= vis[cur.X][cur.Y] + 1 || vis[nx][ny] == -1) continue;            
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}