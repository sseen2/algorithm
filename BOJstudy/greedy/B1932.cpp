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
const int N = 505;

int n;
int t[N][N];
int dp[N][N];

int func(int a, int k) {
    if (k == n) return t[k][a];
    if (dp[k][a] != -1) return dp[k][a];

    int result = func(a, k + 1) + t[k][a];
    result = max(result, func(a + 1, k + 1) + t[k][a]);
    dp[k][a] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> t[i][j];
        }
    }

    for (int i = 0; i < N; i++)
        fill(dp[i], dp[i] + N, -1);
    
    cout << func(0, 0);
}