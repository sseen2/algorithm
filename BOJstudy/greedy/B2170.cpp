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
const int N = 1'000'005;

ll n, st, en, rs;
vector<pl> l;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        l.push_back({a, b});
    }
    sort(l.begin(), l.end());
    st = l[0].X;
    en = l[0].Y;

    for (int i = 1; i < n; i++) {
        if (l[i].X < en && l[i].Y <= en) continue;
        else if (l[i].X <= en && l[i].Y >= en) en = l[i].Y;
        else {
            rs += en - st;
            st = l[i].X;
            en = l[i].Y;
        }
    }
    rs += en - st;
    cout << rs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}