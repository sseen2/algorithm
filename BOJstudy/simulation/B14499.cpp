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

int n, m, x, y, k, dir;
int maps[25][25];
int dice[4][3];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dice[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void east() {
    int tmp = dice[3][1];
    dice[3][1] = dice[1][2];
    dice[1][2] = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = tmp;
}

void west() {
    int tmp = dice[3][1];
    dice[3][1] = dice[1][0];
    dice[1][0] = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = tmp;
}

void north() {
    int tmp = dice[0][1];
    for (int i = 0; i < 3; i++) {
        dice[i][1] = dice[i + 1][1];
    }
    dice[3][1] = tmp;
}

void south() {
    int tmp = dice[3][1];
    for (int i = 3; i > 0; i--) {
        dice[i][1] = dice[i - 1][1];
    }
    dice[0][1] = tmp;
}

void dicemove() {
    if (dir == 1) east();
    else if (dir == 2) west();
    else if (dir == 3) north();
    else if (dir == 4) south();
}

void solve() {
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> dir;
        int nx = x + dx[dir - 1];
        int ny = y + dy[dir - 1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        // print();
        dicemove();
        cout << dice[1][1] << nl;
        if (maps[nx][ny] == 0) maps[nx][ny] = dice[3][1];
        else if (maps[nx][ny] != 0) {
            dice[3][1] = maps[nx][ny];
            maps[nx][ny] = 0;
        }
        x = nx; y = ny;
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