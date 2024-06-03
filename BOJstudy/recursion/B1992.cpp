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

int board[70][70];

void func(int n, int x, int y) {
    if (n == 1) {
        cout << board[x][y];
        return;
    }

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[x][y] != board[i][j]) {
                cout << "(";    
                int k = n / 2;
                func(k, x, y);
                func(k, x, y + k);
                func(k, x + k, y);
                func(k, x + k, y + k);
                cout << ")";
                return;
            }
        }
    }
    cout << board[x][y];
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    func(n, 0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}