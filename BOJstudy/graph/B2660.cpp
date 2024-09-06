#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 55;

int n, mn = MX;
vi g[N];
int dist[N];
vi rs;

void solve() {
    cin >> n;
    while (1) {
        int a, b; cin >> a >> b;
        if (a == -1 && b == -1) break;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        fill(dist, dist + N, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;

        int cnt = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            cnt = dist[cur];
            for (auto nxt : g[cur]) {
                if (dist[nxt] != -1) continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }

        if (mn == cnt) rs.push_back(i);
        else if (mn > cnt) {
            rs.clear();
            mn = cnt;
            rs.push_back(i);
        }
    }

    cout << mn << " " << rs.size() << nl;
    for (auto e : rs) cout << e << " ";
} 


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}