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

int n, m;
unordered_map<string, int> pn;
string ps[100005];

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string name; cin >> ps[i];
        pn[ps[i]] = i;
    }

    while (m--) {
        string s; cin >> s;
        if (!isdigit(s[0])) cout << pn[s] << nl;
        else cout << ps[stoi(s)] << nl;
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