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
const int K = 10'005;

int k, n;
int l[K];

// mid 길이로 잘랐을 때 n개 이상의 랜선을 얻을수 있는가?
bool check(int mid) {
    ll cnt = 0;
    for (int i = 0; i < k; i++) {
        if (l[i] >= mid) cnt += 1LL * l[i] / mid;
    }
    return cnt >= n;
}

ll bs() {
    ll lo = 1, hi = 1LL * INT_MAX + 1;
    // check(lo) = T, check(hi) = F
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

void solve() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> l[i];
    cout << bs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}