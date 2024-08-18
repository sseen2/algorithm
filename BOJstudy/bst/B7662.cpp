#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

void solve() {
    int n; cin >> n;
    multiset<int> q;
    for (int i = 0; i < n; i++) {
        char cmd; int a; cin >> cmd >> a;
        if (cmd == 'I') q.insert(a);
        else {
            if (q.empty()) continue;
            auto it = q.begin();
            if (a == -1) q.erase(it);
            else {
                it = q.end(), it--;
                q.erase(it);
            }
        }
    }

    if (!q.empty()) {
        auto it = q.end(); it--;
        cout << *it << " ";
        it = q.begin();
        cout << *it;
    }
    else cout << "EMPTY";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}