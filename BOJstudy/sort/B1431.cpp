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
string s[55];

bool cmp (string a, string b) {
    int acnt = 0, bcnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') continue;
        acnt += a[i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        if (b[i] >= 'A' && b[i] <= 'Z') continue;
        bcnt += b[i] - '0';
    }
    // cout << acnt << " " << bcnt << nl;
    if (a.length() != b.length()) return a.length() < b.length();
    else if (acnt != bcnt) return acnt < bcnt;
    else return a < b;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) cout << s[i] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}