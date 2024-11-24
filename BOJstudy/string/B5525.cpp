#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int N = 1'000'005;

int n, m, cnt;
string s;

void solve() {
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        if (s[i] == 'O') continue;
        int k = 0;
        while (s[i + 1] == 'O' && s[i + 2] == 'I') {
            k++;
            if (k == n) {
                k--;
                cnt++;
            }
            i += 2;
        }
    }

    cout << cnt;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}