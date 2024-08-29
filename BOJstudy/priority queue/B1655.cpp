#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

void solve() {
    int n; cin >> n;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int a; 
    for (int i = 1; i <= 2; i++) {
        cin >> a;
        pq2.push(a);
        cout << pq2.top() << nl;
    }

    for (int i = 3; i <= n; i++) {
        cin >> a;
        if (pq2.top() > a) pq1.push(a);
        else pq2.push(a);

        if (pq2.size() > (i / 2) + 1) { pq1.push(pq2.top()); pq2.pop(); }
        else if (pq2.size() < (i / 2) + 1) { pq2.push(pq1.top()); pq1.pop(); }
        
        cout << pq2.top() << nl;
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