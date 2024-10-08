#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 205;
int n, m, a, b, c;
int p[N][N];
int nxt[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(p[i], p[i] + n + 1, MX);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (p[a][b] > c) {
            p[a][b] = c;
            p[b][a] = c;
            nxt[a][b] = b;
            nxt[b][a] = a;
        }
    }
    for (int i = 1; i <= n; i++) p[i][i] = 0;

    for (int h = 1; h <= n; h++) 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                if (p[i][j] > p[i][h] + p[h][j]) {
                    p[i][j] = p[i][h] + p[h][j];
                    p[j][i] = p[j][h] + p[h][i];
                    nxt[i][j] = nxt[i][h];
                    nxt[j][i] = nxt[j][h];
                }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << nxt[i][j] << " ";
        }
        cout << nl;
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}