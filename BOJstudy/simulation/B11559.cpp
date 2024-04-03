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

int n = 12;
int m = 6; 
char board[12][6];
int vis[12][6];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void downpuyo() {
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        int cur = n - 1;
        for (int j =  n - 2; j >= 0; j--) {
            if (board[j][i] == '.') continue;
            tmp = j + 1;
            while (board[tmp][i] == '.' && tmp < cur) {
                tmp++;
            }

            if (board[tmp][i] == '.') {
                board[tmp][i] = board[j][i];
                board[j][i] = '.';
                cur = tmp - 1;
            }
            else if (board[tmp - 1][i] == '.') {
                board[tmp - 1][i] = board[j][i];
                board[j][i] = '.';
                cur = tmp - 1;
            }
        }
    }
}

void filldot() {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 1) board[i][j] = '.';
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    } 

    int outcnt = 0; 
    bool end = false;   // 뿌요는 있지만, 연결해서 4개 이상이 없는 경우
    while (1) {
        end = true;
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                if (board[j][i] == '.') { continue; }
                if (vis[j][i] == 1) continue;
                int cnt = 1;
                queue<pi> q;
                q.push({j, i});
                vis[j][i] = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] != board[cur.X][cur.Y]) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                        cnt++;
                    }
                }

                if (cnt >= 4) {
                    end = false;
                    filldot();
                }
                for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
            }
        }
        if (end) break;
        downpuyo();
        if (!end) outcnt++;
    }

    cout << outcnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}