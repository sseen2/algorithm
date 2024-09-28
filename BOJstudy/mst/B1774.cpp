#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define X first
#define Y second
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef tuple<double, int, int> ti;

const char nl = '\n';
const int N = 1005;
ll n, m, a, b, cnt, sz;
double rs;
vector<pi> xy;
vi p(N, -1);
vector<ti> e;

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { 
        int x, y; cin >> x >> y; 
        xy.push_back({x, y}); 
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        e.push_back({0, a, b});
    }

    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) {
            a = xy[i].X - xy[j].X;
            b = xy[i].Y - xy[j].Y;
            e.push_back({sqrt((a * a) + (b * b)), i + 1, j + 1});
        }
    sort(all(e));

    for (int i = 0; i < e.size(); i++) {
        double cost;
        tie(cost, a, b) = e[i];
        if (!merge(a, b)) continue;
        cnt++;
        rs += cost;
        if (cnt == n - 1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << rs;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}