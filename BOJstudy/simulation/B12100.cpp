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

int n, mx;
int board[25][25];
int cpyboard[5][25][25];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void left() {
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 1; j < n; j++) {
            if (board[i][j] == 0) continue;
            if (board[i][cur] == 0) {
                board[i][cur] = board[i][j];
                board[i][j] = 0;
                continue;
            }
            int tmp = j - 1;
            while(board[i][tmp] == 0 && tmp > cur) {
                tmp--;
            }

            if (board[i][tmp] == board[i][j]) {
                cur = tmp + 1;
                board[i][tmp] += board[i][tmp];
                board[i][j] = 0;
            }
            else if (board[i][tmp + 1] == 0) {
                board[i][tmp + 1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void down() {
    for (int i = 0; i < n; i++) {
        int cur = n - 1;
        for (int j = n - 2; j >= 0; j--) {
            if (board[j][i] == 0) continue;
            if (board[cur][i] == 0) {
                board[cur][i] = board[j][i];
                board[j][i] = 0;
                continue;
            }
            int tmp = j + 1;
            while (board[tmp][i] == 0 && tmp < cur) {
                tmp++;
            }

            if (board[tmp][i] == board[j][i]) {
                cur = tmp - 1;
                board[tmp][i] += board[tmp][i];
                board[j][i] = 0;
            }
            else if (board[tmp - 1][i] == 0) {
                board[tmp - 1][i] = board[j][i];
                board[j][i] = 0;
            }
        }
    }
}

void right() {
    for (int i = 0; i < n; i++) {
        int cur = n - 1;
        for (int j = n - 2; j >= 0; j--) {
            if (board[i][j] == 0) continue;
            if (board[i][cur] == 0) {
                board[i][cur] = board[i][j];
                board[i][j] = 0;
                continue;
            }
            int tmp = j + 1;
            while(board[i][tmp] == 0 && tmp < cur) {
                tmp++;
            }

            if (board[i][tmp] == board[i][j]) {
                cur = tmp - 1;
                board[i][tmp] += board[i][tmp];
                board[i][j] = 0;
            }
            else if (board[i][tmp - 1] == 0) {
                board[i][tmp - 1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void up() {
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 1; j < n; j++) {
            if (board[j][i] == 0) continue;
            if (board[cur][i] == 0) {
                board[cur][i] = board[j][i];
                board[j][i] = 0;
                continue;
            }
            int tmp = j - 1;
            while(board[tmp][i] == 0 && tmp > cur) {
                tmp--;
            }

            if (board[tmp][i] == board[j][i]) {
                cur = tmp + 1;
                board[tmp][i] += board[tmp][i];
                board[j][i] = 0;
            }
            else if (board[tmp + 1][i] == 0) {
                board[tmp + 1][i] = board[j][i];
                board[j][i] = 0;
            }
        }
    }
}

void cpyarr(int num, int idx) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num == 0) board[i][j] = cpyboard[idx][i][j];
            else if (num == 1) cpyboard[idx][i][j] = board[i][j];
        }
    }
}

void func(int k) {
    if (k == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mx = max(board[i][j], mx);
            }
        }
        return;
    }

    // 0: left, 1: down, 2: right, 3: up
    for (int i = 0; i < 4; i++) {
        cpyarr(1, k);
        if (i == 0) {   
            left();
        }
        else if (i == 1) {
            down();
        }
        else if (i == 2) {
            right();
        }
        else if (i == 3) {
            up();
        }
        // cout << i << " " << k << nl;
        // print();
        func(k + 1);
        cpyarr(0, k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    func(0);
    cout << mx;
}