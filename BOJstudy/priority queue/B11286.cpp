#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x != 0) pq.push(x);
        else {
            if (pq.empty()) cout << 0 << nl;
            else { cout << pq.top() << nl; pq.pop(); }
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