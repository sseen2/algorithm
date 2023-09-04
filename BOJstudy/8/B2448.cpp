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

char board[3100][6200];

void star(int n, int x, int y) {
    if (n == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        board[x + 2][y - 2] = '*';
        board[x + 2][y - 1] = '*';
        board[x + 2][y] = '*';
        board[x + 2][y + 1] = '*';
        board[x + 2][y + 2] = '*';
        
        return;
    }

    int k = n / 2;
    star(k, x, y);
    star(k, x + k, y - k);
    star(k, x + k, y + k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        fill(board[i], board[i] + 2 * n, ' ');
    star(n, 0, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cout << board[i][j];
        }
        cout << nl;
    }
}