#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int N = 1030;

int n, m;
int board[N][N];
int sum[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            sum[i][j] = board[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << nl;
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}