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

int n, m, k;
int board[45][45];
int sticker[100][15][15];
int tmp[100][15][15];
int _size[100][3];

void print() {
    cout << nl;
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}

void rotate(int idx, int r, int c) {
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            tmp[idx][j][r - i - 1] = sticker[idx][i][j];
    
    for (int i = 0; i < c; i++) 
        for (int j = 0; j < r; j++) 
            sticker[idx][i][j] = tmp[idx][i][j];
}

bool check(int idx, int r, int c, int stickersize) {
    int ssize = 0;
    for (int i = 0; i <= n - r; i++) {
        for (int j = 0; j <= m - c; j++) {
            ssize = 0;
            for (int a = i; a < i + r; a++) {
                for (int b = j; b < j + c; b++) {
                    if (board[a][b] == 0 && sticker[idx][a - i][b - j] == 1) ssize++; 
                }
            }
            if (stickersize == ssize) {
                for (int a = i; a < i + r; a++) {
                    for (int b = j; b < j + c; b++) {
                        if (board[a][b] == 0 && sticker[idx][a - i][b - j] == 1) board[a][b] = 1; 
                    }
                }
                // print();
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> _size[i][0] >> _size[i][1];
        for (int j = 0; j < _size[i][0]; j++) {
            for (int h = 0; h < _size[i][1]; h++) {
                cin >> sticker[i][j][h];
                if (sticker[i][j][h] == 1) _size[i][2]++;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int dir = 0; dir < 4; dir++) {
            int r, c, ssize = _size[i][2];
            if (dir == 0 || dir == 2) {
                r = _size[i][0];
                c = _size[i][1];
            }
            else if (dir == 1 || dir == 3) {
                r = _size[i][1];
                c = _size[i][0];
            }
            bool put = check(i, r, c, ssize);
            if (put) break;
            rotate(i, r, c);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 1) cnt++;
    cout << cnt;
}