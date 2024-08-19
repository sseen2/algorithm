#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
typedef pair<int, int> pi;

const char nl = '\n';

int n, k; 
vector<pi> je;
multiset<int> b;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int m, v; cin >> m >> v;
        je.push_back({v, m});
    }
    sort(je.begin(), je.end());
    for(int i = 0; i < k; i++) {
        int c; cin >> c;
        b.insert(c);
    }

    ll rs = 0; 
    for (int i = n - 1; i >= 0; i--) {
        auto it = b.lower_bound(je[i].Y);
        if (it == b.end()) continue;
        rs += je[i].X;
        b.erase(it);
    }

    cout << rs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}