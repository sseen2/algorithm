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

int n, cnt = 0; 
int board[15][15];

bool check(int x, int y) {
    // 세로
    for (int i = 0; i < x; i++) {
        if (board[i][y] == 1) return true;
    }

    // 대각선
    int m = 0;
    while (m++ < x) {
        if (x - m < 0 || y - m < 0) break;
        if (board[x - m][y - m] == 1) return true;
    }

    m = 0;
    while (m++ < n) {
        if (x - m < 0 || y + m > n) break;
        if (board[x - m][y + m] == 1) return true;
    }

    return false;
}

void func(int k) {
    if (k == n) {
        cnt++;
    }

    for (int j = 0; j < n; j++) {
        if (check(k, j)) continue;
        board[k][j] = 1;
        func(k + 1);
        board[k][j] = 0;
        }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}