#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 105;
int n, m;
int d[N][N];
int nxt[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, MX);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nxt[a][b] = b;
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int h = 1; h <= n; h++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                if (d[i][h] + d[h][j] < d[i][j]) {
                    d[i][j] = d[i][h] + d[h][j];
                    nxt[i][j] = nxt[i][h];
                }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == MX) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << nl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0 || d[i][j] == MX) {
                cout << "0" << nl;
                continue;
            }

            vi path;
            int st = i;
            while (st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << " ";
            for (auto x : path) cout << x << " ";
            cout << nl;
        }
    }
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}