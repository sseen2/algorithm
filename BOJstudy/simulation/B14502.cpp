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

int n, m, cnt = 0;
int board[10][10];
int arr[5];
bool isused[70];
int cpyboard[10][10];
bool vis[10][10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cpyboard[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void cpyarr() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cpyboard[i][j] = board[i][j];
            vis[i][j] = 0;
        }
    }
}

bool bfs() {
    int ax = arr[0] / m, ay = arr[0] % m, bx = arr[1] / m, by = arr[1] % m, cx = arr[2] / m, cy = arr[2] % m;
    if (board[ax][ay] != 0 || board[bx][by] != 0 || board[cx][cy] != 0) return false;
    cpyarr();
    cpyboard[ax][ay] = 1;
    cpyboard[bx][by] = 1;
    cpyboard[cx][cy] = 1;
    // print();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cpyboard[i][j] != 2) continue;
            if (vis[i][j]) continue;
            queue<pi> q;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || cpyboard[nx][ny] != 0) continue;
                    q.push({nx, ny});
                    cpyboard[nx][ny] = 2;
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return true;
}

int cntzero() {
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cpyboard[i][j] == 0) num++;
        }
    }
    return num;
}

void func(int k, int val) {
    if (k == 3) {
        if (bfs()) cnt = max(cntzero(), cnt);
        // print();
        return;                            
    }

    for (int i = val; i < n * m; i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k + 1, i + 1);
        isused[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    func(0, 0);
    cout << cnt;
}