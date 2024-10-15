#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 405;
int n, m, a, b, c, mn = INT_MAX;
int p[N][N];
int rt[N][N];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << p[i][j] << " ";
        cout << nl;
    } 
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(p[i], p[i] + n + 1, MX);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        p[a][b] = min(p[a][b], c);
    }
    for (int i = 1; i <= n; i++) p[i][i] = 0;

    for (int h = 1; h <= n; h++)
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][h] + p[h][j]);
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            if (p[i][j] + p[j][i] == 0) continue;
            mn = min(p[i][j] + p[j][i], mn);
        }

    if (mn >= MX) cout << -1;
    else cout << mn;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}