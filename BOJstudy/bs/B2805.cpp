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

int n, m;
int l[N];

// 절단기 높이를 mid로 지정했을 때 m 미터 이상의 나무를 가져갈 수 있는가?
bool check(int mid) {
    ll sum = 0;
    for (int i = 0; i < n; i++) 
        if (l[i] > mid) sum += l[i] - mid;
    return sum >= m;
}

int bs() {
    ll lo = 0, hi = 1'000'000'001;
    // check
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> l[i];
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