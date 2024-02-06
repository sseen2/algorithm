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
bool isused1[20];
bool isused2[35];
bool isused3[35];

void func(int k) {
    if (k == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isused1[i] || isused2[k+i] || isused3[k-i+n-1]) continue;
        board[k][i] = 1;
        isused1[i] = 1;
        isused2[k + i] = 1;
        isused3[k - i + n - 1] = 1;
        func(k + 1);
        board[k][i] = 0;
        isused1[i] = 0;
        isused2[k + i] = 0;
        isused3[k - i + n - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}