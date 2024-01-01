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

int ar[100005];
int n;

bool iscycle(int idx) {
    int cur = idx;
    for (int i = 0; i < n; i++) {
        cur = arr[cur];
        if (cur == idx) return true;
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if (!iscycle(i)) ans++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}