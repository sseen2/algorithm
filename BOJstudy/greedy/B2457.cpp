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
const int N = 100005;

int n, cnt = 0, cur = 301;
vector<pi> flowers;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        flowers.push_back({a * 100 + b, c * 100 + d});
    }
    sort(flowers.begin(), flowers.end());
    
    int mx = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (cur >= flowers[i].X) mx = max(mx, flowers[i].Y);
        else {
            if (mx < flowers[i].X) { flag = true; break; }
            if (mx >= flowers[i].Y) continue;
            cur = mx;
            cnt++;
            i--;
            // cout << cnt << " " << cur << " " << mx << nl;
            if (mx > 1130) break;
        }
        if (mx > 1130) {
            cnt ++;
            break;
        }
    }

    if (mx <= 1130 || flag) cout << 0;
    else cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}