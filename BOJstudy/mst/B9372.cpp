#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int n, m, a, b;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a >> b;
    cout << n - 1 << nl;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}