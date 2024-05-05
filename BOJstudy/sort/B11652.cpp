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
ll card[100005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> card[i];
    sort(card, card + n);

    ll mxcnt = 0, num = 0, cnt = 1;

    for (int i = 1; i < n; i++) {
        if (card[i - 1] != card[i]) {
            if (mxcnt < cnt) {
                num = card[i - 1];
                mxcnt = cnt;
            }
            cnt = 1;
        }
        else cnt++;
    }

    if (mxcnt < cnt) num = card[n - 1];
    cout << num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}