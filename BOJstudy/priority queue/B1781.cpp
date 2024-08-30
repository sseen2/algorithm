#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
typedef vector<int> vi;
const char nl = '\n';

ll n, a, b, rs; 
vector<vi> p(200'005); // [데드라인][컵라면 수]
priority_queue<int> pq;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> a >> b; p[a].push_back(b); }

    for (int day = n; day > 0; day--) {
        for (int j = 0; j < p[day].size(); j++) pq.push(p[day][j]);
        if (!pq.empty()) {
            rs += pq.top(); pq.pop();
        }
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