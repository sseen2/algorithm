#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int N = 1'000'005;
int f, s, g, u, d;
int dist[N];

void solve() {
    cin >> f >> s >> g >> u >> d;
    fill(dist, dist + f + 1, -1);

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int up = cur + u;
        int down = cur - d;
        if (up <= f && dist[up] == -1) { 
            dist[up] = dist[cur] + 1;
            q.push(up);
        }
        if (down >= 1 && dist[down] == -1) { 
            dist[down] = dist[cur] + 1;
            q.push(down);
        }
    }

    if (dist[g] == -1) cout << "use the stairs";
    else cout << dist[g];
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}