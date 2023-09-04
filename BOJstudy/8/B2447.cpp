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

char board[6600][6600];

void star(int n, int x, int y, int isStar) {
    if (n == 1) {
        if (isStar) board[x][y] = '*';
        else board[x][y] = ' ';
        return;
    }
    int k = n / 3;
    star(k, x, y, isStar);
    star(k, x, y + k, isStar);
    star(k, x, y + 2 * k, isStar);
    star(k, x + k, y, isStar);
    star(k, x + k, y + k, 0); // 공백
    star(k, x + k, y + 2 * k, isStar);
    star(k, x + 2 * k, y, isStar);
    star(k, x + 2 * k, y + k, isStar);
    star(k, x + 2 * k, y + 2 * k, isStar);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    star(n, 0, 0, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << nl;
    }
}