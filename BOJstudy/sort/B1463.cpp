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

int dp[1000005];

int func(int n) {
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];

    int result = func(n - 1) + 1;
    if (n % 3 == 0) result = min(result, func(n / 3) + 1);
    if (n % 2 == 0) result = min(result, func(n / 2) + 1);
    dp[n] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    fill(dp, dp + 1000005, -1);
    cout << func(n);
}