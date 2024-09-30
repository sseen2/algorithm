#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 105;
const int T = 35;
int n, m, r;    // 지역 개수, 수색 범위, 길의 개수
int t[N];
int sum[N];
int d[N][N];

void solve() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) fill(d[i], d[i] + n + 1, MX);
    for (int i = 0; i < r; i++) {
        int a, b, l; cin >> a >> b >> l;
        if (d[a][b] > l) d[a][b] = l, d[b][a] = l;
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int h = 1; h <= n; h++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                if (d[i][j] > d[i][h] + d[h][j]) 
                    d[i][j] = d[i][h] + d[h][j], d[j][i] = d[j][h] + d[h][i];

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            if (d[i][j] <= m) sum[i] += t[j];

    int rs = 0;
    for (int i = 1; i <= n; i++) rs = max(sum[i], rs);
    cout << rs;
}

// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}