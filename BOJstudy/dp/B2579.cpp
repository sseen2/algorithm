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

int n;
int stair[305];
int dp[2][305];

int func(int c, int k) {
    if (k < 0) return 0;
    if (dp[c][k] != -1) return dp[c][k];

    int result = func(0, k - 2) + stair[k];
    if (c < 2) result = max(result, func(c + 1, k - 1) + stair[k]);
    dp[c][k] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> stair[i];
    for (int i = 0; i < 2; i++)
        fill(dp[i], dp[i] + 305, -1);
    cout << func(0, n - 1);
}