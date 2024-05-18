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

int n, s, lo, hi, sum, mn = 0x3f3f3f3f;
int arr[100'005];

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (lo < n) {
        if (hi == n || sum >= s) sum -= arr[lo++];
        else if (hi == n) break;
        else sum += arr[hi++];
        if (sum >= s) {
            mn = min(mn, hi - lo);
        }
    }

    if (mn == 0x3f3f3f3f) cout << 0;
    else cout << mn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}