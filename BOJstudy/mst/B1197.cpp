#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
typedef vector<int> vi;
const char nl = '\n';
const int N = 10005;
const int M = 100005;
int n, m, cnt = 0, rs = 0;

// 크루스칼 알고리즘
vi p(N, -1);
tuple<int, int, int> edge[M];

int find (int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

void kruskal() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost; cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + m);

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!merge(a, b)) continue;
        rs += cost;
        cnt++;
        if (cnt == n - 1) break;
    }

    cout << rs;
}

// 프림 알고리즘
vector<pi> g[N];    // 가중치, 정점
bool chk[N];        // i번째 정점이 최소 신장 트리에 속해있는지

void prim() {
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
    // prim();
    kruskal();
}