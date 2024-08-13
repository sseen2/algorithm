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
unordered_set<string> s;

void solve() {
    cin >> n;

    while (n--) {
        string name, w;
        cin >> name >> w;
        if (w == "enter") s.insert(name);
        else s.erase(name);
    }

    vector<string> rs(s.begin(), s.end());
    sort(rs.rbegin(), rs.rend());
    for (int i = 0; i < rs.size(); i++) cout << rs[i] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}