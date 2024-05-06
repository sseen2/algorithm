#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int n;
string s[20005];

bool cmp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        if (i != 0 && s[i - 1] == s[i]) continue;
        cout << s[i] << nl;
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