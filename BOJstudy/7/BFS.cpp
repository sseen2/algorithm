#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second

int board[502][502] =
    {{1,1,1,0,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} }
int n = 7, m = 10;
bool visit[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visit[nx][ny] || board[nx][ny] != 1) continue;
            q.push({nx, ny});
            visit[nx][ny] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}