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

int n, mx;
int rope[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> rope[i];
    sort(rope, rope + n, greater<>());

    for (int i = 0; i < n; i++) {
        int w = rope[i] * (i + 1);
        mx = max(mx, w);
    }

    cout << mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}