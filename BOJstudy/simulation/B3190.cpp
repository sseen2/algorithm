#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<int, char> pic;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int n, k, l, r, c, t, dir; // dir: 0 동 1 남 2 서 3 북
int board[110][110];
queue<pic> q;
queue<pi> snake;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void solve() {
    while (1) {
        // print();
        auto move = q.front();
        if (move.X == t && move.Y == 'L') {         // 왼쪽
            q.pop();
            if (dir == 0) dir = 3;
            else --dir;
        } 
        else if (move.X == t && move.Y == 'D') {    // 오른쪽
            q.pop();
            if (dir == 3) dir = 0;
            else ++dir;
        }
        r += dx[dir]; c += dy[dir];
        if (r <= 0 || r > n || c <= 0 || c > n) break;
        if (board[r][c] == 1) break;
        auto cur = snake.front();
        if (board[r][c] != -1) {
            board[cur.X][cur.Y] = 0;
            snake.pop();
        }
        snake.push({r, c});
        board[r][c] = 1; // 한칸 앞으로 
        ++t;             // 시간 추가
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        board[x][y] = -1;   // -1은 사과
    }

    cin >> l;
    while (l--) {
        int x; char c;
        cin >> x >> c;
        q.push({x, c});
    }

    r = 1; c = 1;
    snake.push({r, c});
    board[r][c] = 1;
    solve();

    cout << t + 1;
}