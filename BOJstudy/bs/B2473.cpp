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
const int N = 5005;
#define int ll 
int n; 
ll mn = 1e18;
int a[N];
int result[3];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int c = -(a[i] + a[j]);
            int idx = lower_bound(a, a + n, c) - a;
            if (idx == n) idx--;

            ll abc = abs(a[i] + a[j] + a[idx]);
            if ((a[idx] == a[i] || a[idx] == a[j])) continue;
            if (mn > abc) {
                mn = abc;
                result[0] = a[i];
                result[1] = a[j];
                result[2] = a[idx];
            }

            if (idx != 0) {
                if (a[idx - 1] == a[i] || a[idx - 1] == a[j]) continue;
                abc = abs(a[i] + a[j] + a[idx - 1]);
                if (mn > abc) {
                    mn = abc;
                    result[0] = a[i];
                    result[1] = a[j];
                    result[2] = a[idx - 1];
                }
            }
        }
    }
    sort(result, result + 3);
    cout << result[0] << " " << result[1] << " " << result[2];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}