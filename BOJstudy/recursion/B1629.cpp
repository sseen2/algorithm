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

ll func(ll a, ll b, ll c) {
    if (b == 1) return a % c;
    ll result = func(a, b / 2, c);
    result = result * result % c;
    if (b % 2 == 0) return result;
    return result * a % c;
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    cout << func(a, b, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}