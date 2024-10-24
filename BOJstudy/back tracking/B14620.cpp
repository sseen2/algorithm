#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 15;
int n, mn = MX;
int board[N][N];
bool vis[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << vis[i][j] << " ";
        cout << nl;
    }
    cout << nl;
}

bool isVis(int x, int y) {
    if (vis[x][y]) return false;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (vis[nx][ny]) return false;
    }
    return true;
}

int fillVis(int x, int y, bool val) {
    int rs = board[x][y];
    vis[x][y] = val;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        vis[nx][ny] = val;
        rs += board[nx][ny];
    }
    return rs;
}

void func(int k, int w) {
    if (k == 3) {
        mn = min(mn, w);
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (!isVis(i, j)) continue;
            int val = fillVis(i, j, 1);
            func(k + 1, w + val);
            fillVis(i, j, 0);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];
    func(0, 0);
    cout << mn;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}