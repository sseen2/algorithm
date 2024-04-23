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

int n, m, isend = 0, num, mn = INT_MAX;
char board[15][15];
char cpyboard[15][15][15];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        } 
        cout << nl;
    }
    cout << nl;
}

void Left() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j] == '.' || board[i][j] == '#' || board[i][j] == 'O') continue;
            int tmp = j;
            while (tmp-- > 0) {
                if (board[i][tmp] == 'O' && board[i][j] == 'R') {
                    board[i][j] = '.';
                    isend = 1;
                    break;
                }

                if (board[i][tmp] == 'O' && board[i][j] == 'B') {
                    board[i][j] = '.';
                    isend = 2;
                    return;
                }

                if (board[i][tmp] != '.') {
                    board[i][tmp + 1] = board[i][j];
                    if (tmp + 1 != j) board[i][j] = '.';
                    break;
                }
            }
        }
    }
}

void Up () {
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (board[i][j] == '.' || board[i][j] == '#' || board[i][j] == 'O') continue;
            int tmp = i;
            while (tmp-- > 0) {
                if (board[tmp][j] == 'O' && board[i][j] == 'R') {
                    board[i][j] = '.';
                    isend = 1;
                    break;
                }

                if (board[tmp][j] == 'O' && board[i][j] == 'B') {
                    board[i][j] = '.';
                    isend = 2;
                    return;
                }

                if (board[tmp][j] != '.') {
                    board[tmp + 1][j] = board[i][j];
                    if (tmp + 1 != i) board[i][j] = '.';
                    break;
                }
            }
        }
    }
}

void Right() {
    for (int i = 0; i < n; i++) {
        int cur = m;
        for (int j = m - 1; j >= 0; j--) {
            if (board[i][j] == '.' || board[i][j] == '#' || board[i][j] == 'O') continue;
            int tmp = j;
            while (tmp++ < m) {
                if (board[i][tmp] == 'O' && board[i][j] == 'R') {
                    board[i][j] = '.';
                    isend = 1;
                    break;
                }

                if (board[i][tmp] == 'O' && board[i][j] == 'B') {
                    board[i][j] = '.';
                    isend = 2;
                    return;
                }

                if (board[i][tmp] != '.') {
                    board[i][tmp - 1] = board[i][j];
                    if (tmp - 1 != j) board[i][j] = '.';
                    break;
                }
            }
        }
    }
}

void Down () {
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][j] == '.' || board[i][j] == '#' || board[i][j] == 'O') continue;
            int tmp = i;
            while (tmp++ < n) {
                if (board[tmp][j] == 'O' && board[i][j] == 'R') {
                    board[i][j] = '.';
                    isend = 1;
                    break;
                }

                if (board[tmp][j] == 'O' && board[i][j] == 'B') {
                    board[i][j] = '.';
                    isend = 2;
                    return;
                }

                if (board[tmp][j] != '.') {
                    board[tmp - 1][j] = board[i][j];
                    if (tmp - 1 != i) board[i][j] = '.';
                    break;
                }
            }
        }
    }
}

void tilt(int dir) {
    if (dir == 0) Left();
    if (dir == 1) Up();
    if (dir == 2) Right();
    if (dir == 3) Down();
}

void cpyarr(int num, int idx) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (num == 0) cpyboard[idx][i][j] = board[i][j];
            else if (num == 1) board[i][j] = cpyboard[idx][i][j];
        }
    }
}

void func(int k) {
    if (isend != 0 || k == 11) {
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        cpyarr(0, k);
        tilt(dir);
        if (isend == 1) mn = min(mn, k);
        func(k + 1);
        cpyarr(1, k);
        isend = 0;
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

    func(1);

    if (mn == INT_MAX) cout << -1;
    else cout << mn;
}