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

int paper[2200][2200];
int cnt[3];

void func(int n, int x, int y) {
    if (n == 1) {
        cnt[paper[x][y] + 1]++;
        return;
    }

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[x][y] != paper[i][j]) {
                int k = n / 3;
                func(k, x, y);
                func(k, x, y + k);
                func(k, x, y + 2 * k);
                func(k, x + k,y);
                func(k, x + k, y + k);
                func(k, x + k, y + 2 * k);
                func(k, x + 2 * k, y);
                func(k, x + 2 * k, y + k);
                func(k, x + 2 * k, y + 2 * k);
                return;
            }
        }
    }
    cnt[paper[x][y] + 1]++;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    func(n, 0, 0);
    
    for (int i = 0; i < 3; i++) cout << cnt[i] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}