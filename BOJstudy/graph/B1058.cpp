#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

typedef vector<int> vi;

const char nl = '\n';
const int N = 55;

int n, mx = -1;
vi g[N];
int dist[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string input; cin >> input;
        for (int j = 0; j < n; j++) {
            if (input[j] == 'N') continue;
            g[i].push_back(j + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        fill(dist, dist + N, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : g[cur]) {
                if (dist[nxt] != -1) continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[j] <= 0) continue;
            if (dist[j] <= 2) cnt++;
        }
        mx = max(mx, cnt);
    }

    cout << mx;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}