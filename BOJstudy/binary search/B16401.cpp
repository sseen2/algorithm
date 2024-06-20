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

int m, n;
int l[N];

// mid 길이로 잘랐을 때 나눠줄 수 있는 과자가 m개인가?
bool check(int mid) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) 
        cnt += l[i] / mid;
    return cnt >= m;
}

int bs() {
    int lo = 0, hi = 1'000'000'001;
    // check(lo) = T, check(hi) = F
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

void solve() {
    cin >> m >> n;
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