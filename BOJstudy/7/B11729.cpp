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

void hanoi(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << nl;
        return;
    }
    hanoi(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << nl;
    hanoi(6 - a - b, b, n - 1);
}

void solve() {
    int n; cin >> n;
    cout << (1 << n) - 1 << nl;
    hanoi(1, 3, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}