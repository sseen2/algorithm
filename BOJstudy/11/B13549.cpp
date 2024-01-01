#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';

int n, m;
int dist[200005];
int dx[] = {2, -1, 1};

void solve() {
    cin >> n >> m;

    if(n == m) {
        cout << 0;
        return;
    }
    
    queue<int> q;
    q.push(n);
    dist[n] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int dir = 0; dir < 3; dir++) {
            if (dx[dir] != 2) {
                int nx = cur + dx[dir];
                if (nx < 0 || nx > 100001) continue;
                if (dist[nx] != 0) continue;
                dist[nx] = dist[cur] + 1;
                q.push(nx);
                if (nx == m) {
                    cout << dist[m] - 1;
                    return;
                }
            }
            else {
                int nx = cur * dx[dir];
                if (nx < 0 || nx > 200000) continue;
                if (dist[nx] != 0) continue;
                dist[nx] = dist[cur];
                q.push(nx);
                if (nx == m) {
                    cout << dist[m] - 1;
                    return;
                }
            }

            // for (int i = 1; i <= 2 * m; i++) cout << dist[i] << " ";
            // cout << nl;
        }  
        // cout << nl;
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}