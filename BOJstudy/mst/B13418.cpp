#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int N = 1005;
const int M = 500'000;
int n, m, a, b, cost, good, bad;
vi p(N, -1);
ti e[M];

int find(int x) {
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

int kruskal() {
    int rs = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        tie(cost, a, b) = e[i];
        if (!merge(a, b)) continue;
        cnt++;
        if (!cost) rs++;
        if (cnt == n - 1) break;
    }
    return rs;
}

void solve() {
    cin >> n >> m;
    cin >> a >> b >> cost;
    if (!cost) { good++; bad++; }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> cost;
        e[i] = {cost, a, b};
    }

    // 최적의 피로도
    sort(e, e + m, greater<>());
    good += kruskal();

    // 최악의 피로도
    fill(all(p), -1);
    sort(e, e + m);
    bad += kruskal();

    cout << (bad * bad) - (good * good);
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}