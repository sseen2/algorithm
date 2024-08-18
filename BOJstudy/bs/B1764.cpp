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
const int N = 500'005;

int n, m, cnt;
string l[N], s[N];
vector<string> o;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < m; i++) cin >> s[i];
    sort(l, l + n);
    for (int i = 0; i < m; i++) {
        if (binary_search(l, l + n, s[i])) {
            cnt++;
            o.push_back(s[i]);
        }
    }
    sort(o.begin(), o.end());
    cout << cnt << nl;
    for (int i = 0; i < o.size(); i++) cout << o[i] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}