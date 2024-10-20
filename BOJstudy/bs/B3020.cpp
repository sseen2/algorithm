#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int N = 200005;
int n, h, mn = MX, cnt;
vi t, b;    // 종유석, 석순

void solve() {
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i % 2 == 0) b.push_back(a);
        else t.push_back(a);
    }
    sort(all(t)), sort(all(b));

    for (int i = 1; i <= h; i++) {
        int bidx = b.size() - (lower_bound(all(b), i) - b.begin());
        int tidx = t.size() - (lower_bound(all(t), h - i + 1) - t.begin());
        int c = bidx + tidx;

        if (c < mn) { mn = c; cnt = 1; }
        else if (c == mn) cnt++;
    }

    cout << mn << " " << cnt;
}


// *****************************************
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}