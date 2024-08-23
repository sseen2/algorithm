#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int n, m;
set<int> p;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) p.insert(i + 1);
    }

    int d = 1;
    while(m--) {
        int q; cin >> q;
        if (q == 1) {
            int i; cin >> i;
            if (p.find(i) != p.end()) p.erase(i);
            else p.insert(i);
        }
        else if (q == 2) {
            int x; cin >> x;
            d = (d + x - 1) % n + 1;
            // d += x;
            // if (d > n) d %= n;
            // if (d == 0) d = n;
        }
        else if (q == 3) {
            auto it = p.lower_bound(d);
            if (it == p.end()) {
                it = p.lower_bound(0);
                if (it == p.end()) cout << -1 << nl;
                else cout << *it + (n - d) << nl;
            }
            else cout << *it - d << nl; 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}