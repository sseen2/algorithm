#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
const char nl = '\n';
const int N = 10005;
int n, m, cnt = 0, rs = 0;
vector<pi> g[N];    // 가중치, 정점
bool chk[N];        // i번째 정점이 최소 신장 트리에 속해있는지

// 프림 알고리즘
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost; cin >> a >>  b >> cost;
        g[a].push_back({cost, b});
        g[b].push_back({cost, a});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    // tuple = 가중치, 정점1, 정점2
    // pair = 가중치, 정점2 (가중치의 합만 필요한 경우)
    
    chk[1] = 1;
    for (auto nxt : g[1]) pq.push({nxt.X, nxt.Y});
    while (cnt < n - 1) {
        int cost, a;
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