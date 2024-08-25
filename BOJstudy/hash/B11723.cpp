#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
unordered_set<int> s;

void solve() {
    string cmd; cin >> cmd;
    if (cmd == "add") {
        int x; cin >> x;
        s.insert(x);
    }
    else if (cmd == "remove") {
        int x; cin >> x;
        s.erase(x);
    }
    else if (cmd == "check") {
        int x; cin >> x;
        if (s.find(x) != s.end()) cout << 1 << nl;
        else cout << 0 << nl;
    }
    else if (cmd == "toggle") {
        int x; cin >> x;
        if (s.find(x) != s.end()) s.erase(x);
        else s.insert(x);
    }
    else if (cmd == "all") 
        for (int i = 1; i <= 20; i++) s.insert(i);
    else if (cmd == "empty") s.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}