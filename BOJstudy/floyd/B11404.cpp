#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 105;
int n, m;
int a[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(a[i], a[i] + n + 1, MX);
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = min(a[x][y], z);
    }
    for (int i = 1; i <= n; i++) a[i][i] = 0;

    for (int h = 1; h <= n; h++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                a[i][j] = min(a[i][j], a[i][h] + a[h][j]);
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { 
            if (a[i][j] == MX) cout << "0 ";
            else cout << a[i][j] << " ";
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