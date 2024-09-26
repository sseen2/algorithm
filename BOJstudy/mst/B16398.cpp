#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
typedef pair<int, int> pi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 1005;
int n, a, cnt;
ll cost, rs;
vector<pi> g[N];
bool chk[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            cin >> a;
            g[i].push_back({a, j});
        }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    chk[1] = 1;
    for (auto nxt : g[1]) pq.push({nxt.X, nxt.Y});
    while(cnt < n - 1) {
        tie(cost, a) = pq.top(); pq.pop();
        if (chk[a]) continue;
        rs += cost;
        cnt++;
        chk[a] = 1;
        for (auto nxt : g[a]) 
            if (!chk[nxt.Y]) pq.push({nxt.X, nxt.Y});
    }

    cout << rs;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}