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
int cost[1005][4];
int dp[4][1005];

int func(int rgb, int k) {
    if (k < 0) return 0; 
    if (dp[rgb][k] != -1) return dp[rgb][k];
    
    int result = min(func(1, k - 1) + cost[k][1], func(2, k - 1) + cost[k][2]);
    if (rgb == 0) result = min(result, func(3, k - 1) + cost[k][3]);
    if (rgb == 1) result = min(func(2, k - 1) + cost[k][2], func(3, k - 1) + cost[k][3]);
    if (rgb == 2) result = min(func(1, k - 1) + cost[k][1], func(3, k - 1) + cost[k][3]);
    if (rgb == 3) result = min(func(1, k - 1) + cost[k][1], func(2, k - 1) + cost[k][2]);
    dp[rgb][k] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 4; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < 4; i++) fill(dp[i], dp[i] + 1005, -1);

    cout << func(0, n - 1);
}