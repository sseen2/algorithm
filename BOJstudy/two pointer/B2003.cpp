#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

int n, m, s, e, sum, cnt;
int arr[10005];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (s < n) {
        if (e == n || sum >= m) sum -= arr[s++];
        else if (e == n) break;
        else sum += arr[e++];
        if (sum == m) cnt++;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}