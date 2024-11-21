#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> pi;

const char nl = '\n';
const int D = 10005;

int n, d;
vector<pi> sc[D];
int dp[D];

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int s, e, d; cin >> s >> e >> d;
        sc[s].push_back({e, d});
    }
    for (int i = 0; i <= d; i++) dp[i] = i;

    for (int i = 0; i <= d; i++) {
        for (int j = 0; j < sc[i].size(); j++) {
            int en = sc[i][j].X;
            int cost = sc[i][j].Y;

            for (int k = en; k <= d; k++) 
                dp[k] = min(dp[k], dp[i] + cost + (k - en));
        }
    }

    cout << dp[d];
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}