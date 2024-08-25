#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

void solve() {
    int n; cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 0) {
            auto it = a.begin();
            if (a.empty()) cout << 0 << nl;
            else {
                cout << *it << nl;
                a.erase(a.lower_bound(*it));
            }
        }
        else a.insert(x);
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