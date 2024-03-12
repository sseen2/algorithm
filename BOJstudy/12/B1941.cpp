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

char student[5][5];
int isused[5][5];
int cnt;

bool vis[5][5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool BFS() {
    int cntBFS = 0;
    int cntS = 0;
    for (int i = 0; i < 5; i++) 
        fill(vis[i], vis[i] + 5, 0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (isused[i][j] == 1 && vis[i][j] == 0) {
                queue<pi> q;
                vis[i][j] = 1;
                q.push({i, j});
                cntBFS++;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    if(student[cur.X][cur.Y] == 'S') cntS ++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                        if (vis[nx][ny] == 1 || isused[nx][ny] != 1) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    if (cntBFS == 1 && cntS >= 4) return true;
    else return false;
}

// bool checkS() {
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             if (isused[i][j] == 1 && student[i][j] == 'S') cntS++;
//         }
//     }
//     if (cntS >= 4) return true;
//     else return false;
// }

void func(int k, int val) {
    if (k == 7) {
        if (BFS()) cnt++;
        return;
    }

    for (int i = val; i < 25; i++) {
        int x = i / 5;
        int y = i % 5;
        if (isused[x][y]) continue;
        isused[x][y] = 1;
        func(k + 1, i + 1);
        isused[x][y] = 0;
    }
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            student[i][j] = s[j];
        }
    }

    func(0, 0);
    cout << cnt;
}