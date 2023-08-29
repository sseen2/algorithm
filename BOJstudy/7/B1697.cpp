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

int vis[200005];
int dx[] = {1, -1, 2};
int n, k;

void solve() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);

    if (n == k) {
        cout << 0;
        return;
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int dir = 0; dir < 3; dir++) {
            int nx;
            if (dx[dir] != 2) nx = cur + dx[dir];
            else nx = cur * dx[dir];
            if (nx < 0 || nx > 200000) continue;
            if (vis[nx] != 0) continue;
            vis[nx] = vis[cur] + 1;
            q.push(nx);
            if (nx == k) {
                cout << vis[nx];
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}