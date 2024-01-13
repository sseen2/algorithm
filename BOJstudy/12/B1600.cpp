#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X get<0>
#define Y get<1>
#define Z get<2>

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int k, h, w;
int board[205][205]; // h, w
int dist[205][205][2]; // 0: 말로 움직일 수 있음, 1: 말로 움직일 수 없음 
int kdx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int kdy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print1() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << dist[i][j][0] << " ";
        cout << nl;
    }
}

void print2() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << dist[i][j][1] << " ";
        cout << nl;
    }
}

void solve() {
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 0;
    q.push(make_tuple(0, 0, k));
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x,y,z;
        tie(x,y,z) = cur;
        int horse = Z(cur);
        if (horse > 0) {
            
        }
        for (int i = 0; i < 8; i++) {
            int nx = kdx[i] + X(cur);
            int ny = kdy[i] + Y(cur);
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (dist[nx][ny] > -1 || board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

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