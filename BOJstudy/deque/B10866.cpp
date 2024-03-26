#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    deque<int> d;
    while(n-- > 0) {
        string s; cin >> s;
        if (s == "push_back") {
            int a; cin >> a;
            d.push_back(a);
        }
        else if (s == "push_front") {
            int a; cin >> a;
            d.push_front(a);
        }
        else if (s == "pop_front") {
            if (d.empty()) cout << -1 << "\n";
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if (s == "pop_back") {
            if (d.empty()) cout << -1 << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if (s == "size") {
            cout << d.size() << '\n';
        }
        else if (s == "empty") {
            if (d.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (s == "front") {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.front() << '\n';
        }
        else if (s == "back") {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.back() << '\n';
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