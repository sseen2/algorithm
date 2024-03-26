#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    queue<int> q;
    while (n-- > 0) {
        string s; cin >> s;
        if (s == "push") {
            int a; cin >> a;
            q.push(a);
        }
        else if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            if (!q.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (s == "front") {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (s == "back") {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}