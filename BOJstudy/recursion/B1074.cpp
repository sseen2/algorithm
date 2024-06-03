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

ll func(int n, int r, int c) {
    if (n == 0) {
        return 1;
    }
    ll k = 1 << (n - 1);
    if (r < k && c < k) return func(n - 1, r, c);
    else if (r < k && c >= k) return k * k + func(n - 1, r, c - k);
    else if (r >= k && c < k) return 2 * (k * k) + func(n - 1, r - k, c);
    else return 3 * (k * k) + func(n - 1, r - k, c - k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c; cin >> n >> r >> c;
    cout << func(n, r, c) - 1;
}