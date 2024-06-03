#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int n, m;
int board[1005][1005];
int dist[1005][1005][2];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j][0] << " ";
        }
        cout << nl;
    }
    cout << nl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j][1] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    queue<tuple<int, int, bool>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while (!q.empty()) {
        int x, y; bool z;
        tie(x, y, z) = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!z && board[nx][ny] == 1) {
                q.push({nx, ny, 1});
                dist[nx][ny][1] = dist[x][y][0] + 1;
                continue;
            }
            if (dist[nx][ny][z] > -1 || (z && board[nx][ny] == 1)) continue;
            q.push({nx, ny, z});
            dist[nx][ny][z] = dist[x][y][z] + 1;
        }
    }
    int a = dist[n - 1][m - 1][0], b = dist[n - 1][m - 1][1]; 

    if (min(a, b) != -1)
        cout << min(a, b);
    else if (a == -1)
        cout << b;
    else if (b == -1)
        cout << a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}