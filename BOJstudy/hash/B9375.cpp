#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

void solve() {
    int n; cin >> n;
    unordered_map<string, int> w;
    for (int i = 0; i < n; i++) {
        string s1, s; cin >> s1 >> s;
        w[s]++;
    }

    int rs = 1;
    for (auto e : w) rs *= (e.second + 1);

    cout << rs - 1 << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}