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

ll n, sum;
ll dp[105][10];

void solve() {
    cin >> n;
    for (int i = 1; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j != 9) dp[i][j + 1] += (dp[i - 1][j] % 1'000'000'000);
            if (j != 0) dp[i][j - 1] += (dp[i - 1][j] % 1'000'000'000);
        }
    }
    
    for (int j = 0; j < 10; j++) {
        sum += (dp[n][j] % 1'000'000'000);
    }   

    cout << sum % 1'000'000'000;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}