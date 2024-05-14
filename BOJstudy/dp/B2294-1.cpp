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

int n, k;
int coin[105];
int dp[10005];

int func(int k) {
    if (k == 0) return 0;
    if (dp[k] != -1) return dp[k];

    int result = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (k >= coin[i]) result = min(result, func(k - coin[i]) + 1);
    }
    dp[k] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];
    fill(dp, dp + 10005, -1);
    
    int result = func(k);
    if(result >= 0x3f3f3f3f) cout << -1;
    else cout << result;
}