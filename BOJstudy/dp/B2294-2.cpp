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
const int IMPOSSIBLE = 1000000000;

int N, K;
int coin[101];
int dp[101][10005];

int func(int n, int k) {
    if (n == N) return (k == 0 ? 0 : IMPOSSIBLE);
    if (dp[n][k] != -1) return dp[n][k];

    int result = func(n + 1, k);
    if (k >= coin[n]) result = min(result, func(n, k - coin[n]) + 1);
    dp[n][k] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> coin[i];
    for (int i = 0; i < 101; i++)
        fill(dp[i], dp[i] + 10'005, -1);
    int result = func(0, K);
    if (result == IMPOSSIBLE) cout << -1;
    else cout << result;
}