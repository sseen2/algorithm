#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

int n, m;
unordered_map<string, string> pw;

void solve() {
    cin >> n >> m;
    while (n--) {
        string s1, s2; cin >> s1 >> s2;
        pw[s1] = s2;
    }

    while (m--) {
        string s; cin >> s;
        cout << pw[s] << nl;
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