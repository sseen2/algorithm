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
const int N = 100005;

int n, m;
int a[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int st = 0, en = 0, mn = 0x7fffffff;
    while (st <= en) {
        if (en == n) break;
        if (en < n && a[en] - a[st] < m) en++;
        else {
            mn = min(mn, a[en] - a[st]);
            st++;
        }
    }

    cout << mn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}