#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 25;
int n, cnt;
int p[N][N];
int rs[N][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
            rs[i][j] = p[i][j];
        }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int h = 1; h <= n; h++) {
                if (h == j || h == i) continue;
                if (p[i][j] == p[i][h] + p[h][j]) rs[i][j] = MX;
                if (p[i][j] > p[i][h] + p[h][j]) { cout << -1; return; }
            }
        }
    }

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            if (rs[i][j] != MX) cnt += rs[i][j];

    cout << cnt / 2;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}