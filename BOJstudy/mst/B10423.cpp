#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int N = 1005;
const int M = 100005;
int n, m, k, a, b, cost, cnt, rs;
vi p(N, -1);
ti e[M + N];

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

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a;
        e[i] = {0, 0, a};
    }
    for (int i = k; i < k + m; i++) {
        cin >> a >> b >> cost;
        e[i] = {cost, a, b};
    }
    sort(e, e + m + k);

    for (int i = 0; i < m + k; i++) {
        tie(cost, a, b) = e[i];
        if (!merge(a, b)) continue;
        rs += cost;
        cnt++;
        if (cnt == n + k - 1) break;
    }

    cout << rs;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}