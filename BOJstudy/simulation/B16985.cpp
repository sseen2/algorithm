#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define make_tuple(a, b, c) t(a, b, c)

typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int outmn = 0x7f7f7f7f;
int board[5][5][5];
int maze[5][5][5];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 0, 1, 0, -1};
int dz[] = {0, 0, 1, 0, -1, 0};
int arr[10];
int dist[5][5][5];
vector<int> order = {0, 1, 2, 3, 4};

void print() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int h = 0; h < 5; h++) {
                cout << maze[i][j][h] << " ";
            }
            cout << nl;
        }
        cout << nl;
    }
    cout << nl;
}

void copyboard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int h = 0; h < 5; h++) {
                maze[i][j][h] = board[order[i]][j][h];
            }
        }
    }
}

void rotate(int idx) {
    int tmp[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp[i][j] = maze[idx][j][5 - i - 1];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            maze[idx][i][j] = tmp[i][j];
        }
    }
}

void bfs() {
    if (maze[0][0][0] == 0) return;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int h = 0; h < 5; h++) {
                dist[i][j][h] = -1;
            }
        }
    }
    queue<ti> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
        if (x == 4 && y == 4 && z == 4) {
            outmn = min(outmn, dist[4][4][4]);
            return;
        }
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if (dist[nx][ny][nz] != -1 || maze[nx][ny][nz] == 0) continue;
            q.push({nx, ny, nz});
            dist[nx][ny][nz] = dist[x][y][z] + 1;
        }
    }
    
    if (dist[4][4][4] == -1) return;
    outmn = min(outmn, dist[4][4][4]);
}

void func(int k) {
    if (k == 5) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < arr[i]; j++) {
                rotate(i);
            }
        }
        bfs();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4 - arr[i]; j++) {
                rotate(i);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int h = 0; h < 5; h++) {
                cin >> board[i][j][h];
            }
        }
    }

    do {
        copyboard();
        // print();
        func(0);
    } while(next_permutation(order.begin(), order.end()));

    if (outmn == 0x7f7f7f7f) cout << -1;
    else cout << outmn;
}