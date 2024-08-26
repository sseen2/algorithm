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
const int N = 200'005;
const int A = 100'005;

int n, k;
int a[N];
int num[A];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int en = 0, mx = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && num[a[en]] < k) {
            num[a[en]]++;
            if (num[a[en]] > k) break;
            en++;
        }
        mx = max(mx, en - st);
        num[a[st]]--;
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