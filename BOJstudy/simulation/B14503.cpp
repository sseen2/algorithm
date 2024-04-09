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

int n, m, r, c, d;  // d == 0 북, 1 동, 2 남, 3 서
int board[55][55];
bool clean[55][55];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << clean[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

bool isclean(int dir) {
    if (dir == 0 && r - 1 >= 0 && !board[r - 1][c]) 
        return clean[r - 1][c];
    else if (dir == 1 && c + 1 < m && !board[r][c + 1]) 
        return clean[r][c + 1];
    else if (dir == 2 && r + 1 < n && !board[r + 1][c]) 
        return clean[r + 1][c];
    else if (dir == 3 && c - 1 >= 0 && !board[r][c - 1]) 
        return clean[r][c - 1];
    return 1;
}

void solve() {
    while (1) {
        if (!clean[r][c]) clean[r][c] = 1;
        // cout << d << nl;
        // print();
        if (d == 0) {
            if (!isclean(3)) { c--; d = 3; continue; }
            if (!isclean(2)) { r++; d = 2; continue; }
            if (!isclean(1)) { c++; d = 1; continue; }
            if (!isclean(0)) { r--; d = 0; continue; }
            if (board[r+1][c]) break;
            r++;
        }
        else if (d == 1) {
            if (!isclean(0)) { r--; d = 0; continue; }
            if (!isclean(3)) { c--; d = 3; continue; }
            if (!isclean(2)) { r++; d = 2; continue; }
            if (!isclean(1)) { c++; d = 1; continue; }
            if (board[r][c-1]) break;
            c--;
        }
        else if (d == 2) {
            if (!isclean(1)) { c++; d = 1; continue; }
            if (!isclean(0)) { r--; d = 0; continue; }
            if (!isclean(3)) { c--; d = 3; continue; }
            if (!isclean(2)) { r++; d = 2; continue; }
            if (board[r-1][c]) break;
            r--;
        }
        else if (d == 3) {
            if (!isclean(2)) { r++; d = 2; continue; }
            if (!isclean(1)) { c++; d = 1; continue; }
            if (!isclean(0)) { r--; d = 0; continue; }
            if (!isclean(3)) { c--; d = 3; continue; }
            if (board[r][c+1]) break;
            c++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (clean[i][j]) cnt++;
        }
    }
    cout << cnt;
}