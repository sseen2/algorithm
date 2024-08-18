#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 2; i < n; i++) {
        if (s[i - 2] == 'P' && s[i - 1] == 'S' && s[i] == '4') s.erase(i--, 1);
        else if (s[i - 2] == 'P' && s[i - 1] == 'S' && s[i] == '5') s.erase(i--, 1);
    }

    cout << s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}