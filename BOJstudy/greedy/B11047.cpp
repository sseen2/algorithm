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

int n, k, cnt;
int arr[15];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = n - 1; i >= 0; i--) {
        cnt += k / arr[i];
        k %= arr[i];
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