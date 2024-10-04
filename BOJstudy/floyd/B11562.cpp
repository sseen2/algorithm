#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 255;
int n, m, a, b, c, k;
int p[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(p[i], p[i] + n + 1, MX);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c) p[a][b] = 0, p[b][a] = 0;
        else p[b][a] = 1, p[a][b] = 0;
    }
    for (int i = 1; i <= n; i++) p[i][i] = 0;
    for (int h = 1; h <= n; h++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = min(p[i][j], p[i][h] + p[h][j]);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        if (a == b) { cout << 0 << nl; continue; }
        cout << p[a][b] << nl;
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}