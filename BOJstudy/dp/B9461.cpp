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
ll p[105];

void solve() {
    cin >> n;
    p[1] = 1; p[2] = 1; p[3] = 1; p[4] = 2; p[5] = 2;
    for (int i = 6; i <= n; i++) {
        p[i] = p[i - 1] + p[i - 5];
    }
    cout << p[n] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}