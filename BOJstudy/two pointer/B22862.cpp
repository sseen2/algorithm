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

int n, k;
int s[N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> s[i];

    int en = 0, mx = 0, cnt = 0;
    for (int st = 0; st < n; st++) {
        while(en < n) {
            if (cnt == k && s[en] % 2 != 0) break;
            if (s[en] % 2 != 0) cnt++;
            en++;
        }
        mx = max(mx, en - st - cnt);
        if (cnt > 0 && s[st] % 2 != 0) cnt--;
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