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

int n, cnt, endtime, en, st;
vector<pi> I;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        I.push_back({b, a});
    }
    sort(I.begin(), I.end());

    for (int i = 0; i < n; i++) {
        tie(en, st) = I[i];
        if (endtime > st) continue;
        cnt++;
        endtime = en;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}