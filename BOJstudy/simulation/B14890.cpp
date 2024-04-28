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

int n, l, cnt;
int board[105][105];
int bridge[105];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void column(int i) {
    bool flag = false;
    for (int j = 1; j < n; j++) {
        if (board[i][j - 1] == board[i][j]) continue;
        queue<int> q;

        if (board[i][j - 1] == board[i][j] - 1) {
            for (int h = j - l; h < j; h++) {
                if (h < 0 || board[i][j - 1] != board[i][h] || bridge[h]) { 
                    flag = true; 
                    break; 
                }
                q.push(h);
            }
            if (flag) break;
        }
        else if (board[i][j - 1] == board[i][j] + 1) {
            for (int h = j; h < l + j; h++) {
                if (h >= n || board[i][j] != board[i][h] || bridge[h]) { 
                    flag = true; 
                    break; 
                }
                q.push(h);
            }
            if (flag) break;
        }
        else { 
            flag = true;
            break;
        }

        while (!q.empty()) {
            bridge[q.front()] = 1;
            q.pop();
        }
    }
    if (!flag) {
        cnt++;
    }
}

void row(int i) {
    bool flag = false;
    for (int j = 1; j < n; j++) {
        if (board[j - 1][i] == board[j][i]) continue;
        queue<int> q;

        if (board[j - 1][i] == board[j][i] - 1) {
            for (int h = j - l; h < j; h++) {
                if (h < 0 || board[j - 1][i] != board[h][i] || bridge[h]) { 
                    flag = true; 
                    break; 
                }
                q.push(h);
            }
            if (flag) break;
        }
        else if (board[j - 1][i] == board[j][i] + 1) {
            for (int h = j; h < l + j; h++) {
                if (h >= n || board[j][i] != board[h][i] || bridge[h]) { 
                    flag = true; 
                    break; 
                }
                q.push(h);
            }
            if (flag) break;
        }
        else { 
            flag = true;
            break;
        }

        while (!q.empty()) {
            bridge[q.front()] = 1;
            q.pop();
        }
    }
    if (!flag) {
        cnt++;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        fill(bridge, bridge + n, 0);
        column(i);

        fill(bridge, bridge + n, 0);
        row(i);
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    // print();
    solve();
}