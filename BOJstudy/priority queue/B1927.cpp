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

void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소 힙
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x != 0) pq.push(x); 
        else 
            if (pq.empty()) cout << 0 << nl;
            else { cout << pq.top() << nl; pq.pop(); }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}