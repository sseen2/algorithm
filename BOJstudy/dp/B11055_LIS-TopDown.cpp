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
const int N = 1005;

int n;
int arr[N];
int dp[N][N];

int func(int pre, int k) {
    if (k == n) return 0;
    if (dp[pre][k] != -1) return dp[pre][k];

    int result = func(pre, k + 1);
    if (pre < arr[k]) result = max(result, func(arr[k], k + 1) + arr[k]);
    dp[pre][k] = result;
    return result;
}
 
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) fill(dp[i], dp[i] + N, -1);
    cout << func(0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}