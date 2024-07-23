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
const int N = 15;

int n, k, cnt;
int coin[N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];

    int cur = n - 1;
    while (k > 0) {
        if (k - coin[cur] < 0) cur--;
        else {
            cnt += k / coin[cur];
            k -= (k / coin[cur] * coin[cur]);
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}