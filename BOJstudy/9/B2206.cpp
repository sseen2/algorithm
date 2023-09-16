#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define X get<0>
#define Y get<1>
#define Z get<2>

typedef vector<ll> vl;

const char nl = '\n';

int n, m;
int board[1010][1010];
int dist1[1010][1010]; // 벽을 안 뚫었을 때
int dist2[1010][1010]; // 벽을 뚫었을 때
int dx[] = {1, 0, -1, 0}; // 오 아 왼 위
int dy[] = {0, 1, 0, -1};

void print1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist1[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void print2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist2[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
            dist1[i][j] = -1;
            dist2[i][j] = -1;
        }
    }

    queue<tuple<int, int, bool>> q; 
    q.push(make_tuple(0, 0, 0)); 
    dist1[0][0] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x,y,z;
        tie(x,y,z) = cur;
        for (int dir = 0; dir < 4; dir++) {
            int nx = X(cur) + dx[dir];
            int ny = Y(cur) + dy[dir];
            bool isVis = Z(cur);
            // 범위를 벗어난 경우 continue
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 방문한 칸임 || 벽을 이미 통과한 후 또 벽이 나온 경우 continue
            if ((!isVis && dist1[nx][ny] != -1) || (isVis && dist2[nx][ny] != -1) || (isVis && board[nx][ny])) continue;
            // 현재 벽인데 다음 탐색하는 곳이 벽인 경우 continue

            // 현재 칸이 0이고 다음 칸이 1(벽)인 경우
            bool flag = false; // 벽 현재 뚫는지
            if (!isVis && board[nx][ny]) {
                flag = 1;
                isVis = 1;
            }
            if(flag) dist2[nx][ny] = dist1[x][y] + 1;
            else {
                if(isVis)
                    dist2[nx][ny] = dist2[x][y] + 1;
                else dist1[nx][ny] = dist1[X(cur)][Y(cur)] + 1;
            }
            q.push(make_tuple(nx, ny, isVis));
            // isVis
            //print2();
        }
    }

    int a = dist1[n - 1][m - 1], b = dist2[n - 1][m - 1];

    //print1(); print2();

    if (a == -1 && b == -1) cout << -1;
    else if (a == -1) cout << b;
    else if (b == -1) cout << a;
    else cout << min(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}