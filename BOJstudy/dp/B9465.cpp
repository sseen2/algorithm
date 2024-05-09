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

int n;
int board[2][100'005];
int dp[100'005][3];

int func(int c, int s) {
    if (c == n) return 0; // base case
    if (dp[c][s] != -1) return dp[c][s];

    int result = func(c + 1, 0);
    if (s != 2) result = max(result, board[1][c] + func(c + 1, 2));
    if (s != 1) result = max(result, board[0][c] + func(c + 1, 1));
    dp[c][s] = result;
    return result;
}

void solve() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 100005; i++) {
        fill(dp[i], dp[i] + 3, -1);
    }

    cout << func(0, 0) << nl;
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}