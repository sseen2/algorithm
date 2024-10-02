#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 205;
int n, m, a, b, t, k, mn = MX;
int p[N][N];
int rt[N][N];   // 왕복 거리
bool c[N];
bool rs[N];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << rt[i][j] << " ";
        cout << nl;
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(p[i], p[i] + n + 1, MX);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        p[a][b] = t;
    }
    cin >> k;
    for (int i = 0; i < k; i++) { cin >> a; c[a] = 1; }
    for (int i = 1; i <= n; i++) p[i][i] = 0;

    for (int h = 1; h <= n; h++) 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][h] + p[h][j]);
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            rt[i][j] = p[i][j] + p[j][i];

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            if (!c[j]) continue;
            mx = max(rt[i][j], mx);
        }
        if (mn > mx) { 
            fill(rs, rs + n + 1, 0);
            mn = mx; 
            rs[i] = 1; 
        }
        else if (mn == mx) rs[i] = 1;
    }

    for (int i = 1; i <= n; i++) if (rs[i]) cout << i << " ";
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}