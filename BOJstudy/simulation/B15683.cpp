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

int n, m, cnt;
int board[10][10];
int idx[8][2];
int mn = 100;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void fillRight(int x, int y, int num) {
    while (y++ < m - 1) {
        if (board[x][y] == 6) break;
        if (board[x][y] > 0) continue;
        if (num == -1) board[x][y] -= 1;
        if (num == 0) board[x][y] += 1;
    }
}

void fillDown(int x, int y, int num) {
    while (x++ < n - 1) {
        if (board[x][y] == 6) break;
        if (board[x][y] > 0) continue;
        if (num == -1) board[x][y] -= 1;
        if (num == 0) board[x][y] += 1;
    }
}

void fillLeft(int x, int y, int num) {
    while (y-- > 0) {
        if (board[x][y] == 6) break;
        if (board[x][y] > 0) continue;
        if (num == -1) board[x][y] -= 1;
        if (num == 0) board[x][y] += 1;
    }
}

void fillUp(int x, int y, int num) {
    while (x-- > 0) {
        if (board[x][y] == 6) break;
        if (board[x][y] > 0) continue;
        if (num == -1) board[x][y] -= 1;
        if (num == 0) board[x][y] += 1;
    }
}

void fill(int i, int x, int y, int num) {
    if (i == 1) { // cctv 1
        fillRight(x, y, num);
    }
    else if (i == 2) {
        fillDown(x, y, num);
    }
    else if (i == 3) {
        fillLeft(x, y, num);
    }
    else if (i == 4) {
        fillUp(x, y, num);
    }
    else if (i == 5) { // cctv 2
        fillRight(x, y, num);
        fillLeft(x, y, num);
    }
    else if (i == 6) {
        fillUp(x, y, num);
        fillDown(x, y, num);
    }
    else if (i == 7) { // cctv 3
        fillUp(x, y, num);
        fillRight(x, y, num);
    }
    else if (i == 8) {
        fillRight(x, y, num);
        fillDown(x, y, num);
    }
    else if (i == 9) {
        fillDown(x, y, num);
        fillLeft(x, y, num);
    }
    else if (i == 10) {
        fillLeft(x, y, num);
        fillUp(x, y, num);
    }
    else if (i == 11) {  // cctv 4
        fillLeft(x, y, num);
        fillUp(x, y, num);
        fillRight(x, y, num);
    }
    else if (i == 12) {
        fillUp(x, y, num);
        fillRight(x, y, num);
        fillDown(x, y, num);
    }
    else if (i == 13) {
        fillRight(x, y, num);
        fillDown(x, y, num);
        fillLeft(x, y, num);
    }
    else if (i == 14) {
        fillDown(x, y, num);
        fillLeft(x, y, num);
        fillUp(x, y, num);
    }
    else if (i == 15) {  // cctv 5
        fillRight(x, y, num);
        fillDown(x, y, num);
        fillLeft(x, y, num);
        fillUp(x, y, num);
    }
}

void func(int k, int val) {
    if (k == 0) {
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) cnt0++;
            }
        }
        mn = min(mn, cnt0);
        // print();
        return;
    }

    // cout << nl << k << nl;
    for (int i = val; i < cnt; i++) {
        int x = idx[i][0];
        int y = idx[i][1];
        // cout << x << " " << y << nl;
        if (board[x][y] == 1) {
            for (int j = 1; j <= 4; j++) {
                fill(j, x, y, -1);
                func(k - 1, i + 1);
                fill(j, x, y, 0);
            }
        }
        else if (board[x][y] == 2) {
            for (int j = 5; j <= 6; j++) {
                fill(j, x, y, -1);
                func(k - 1, i + 1);
                fill(j, x, y, 0);
            }
        }
        else if (board[x][y] == 3) {
            for (int j = 7; j <= 10; j++) {
                fill(j, x, y, -1);
                func(k - 1, i + 1);
                fill(j, x, y, 0);
            }
        }
        else if (board[x][y] == 4) {
            for (int j = 11; j <= 14; j++) {
                fill(j, x, y, -1);
                func(k - 1, i + 1);
                fill(j, x, y, 0);
            }
        }
        else if (board[x][y] == 5) {
            fill(15, x, y, -1);
            func(k - 1, i + 1);
            fill(15, x, y, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 6 && board[i][j] != 0) {
                idx[cnt][0] = i;
                idx[cnt][1] = j;
                cnt++;
            }
        }
    }
    func(cnt, 0);
    cout << mn;
}