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

int k, l;
unordered_map<string, int> n;

void solve() {
    cin >> k >> l;
    for (int i = 0; i < l; i++) {
        string s; cin >> s;
        n[s] = i;
    }
    
    vector<pair<int, string>> rs;
    for (auto e : n) rs.push_back({e.second, e.first});
    sort(rs.begin(), rs.end());

    k = min(k, (int) rs.size());
    for (int i = 0; i < k; i++) cout << rs[i].second << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}