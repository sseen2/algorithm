#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int N = 305;
int n, a, cnt, rs, cost;
vector<pi> g[N];    // 가중치, 정점
bool chk[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        g[i].push_back({a, n + 1});
        g[n + 1].push_back({a, i});
    }
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            cin >> a;
            if (a == 0) continue;
            g[i].push_back({a, j});
        }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    chk[1] = 1;
    for(auto nxt : g[1]) pq.push({nxt.X, nxt.Y});
    while(cnt < n) {
        tie(cost, a) = pq.top(); pq.pop();
        if (chk[a]) continue;
        chk[a] = 1;
        cnt++;
        rs += cost;
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