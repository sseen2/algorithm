#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, i = 1; cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);

    while (q.size() > 1) {
        if (i % 2 != 0) q.pop();
        else {
            q.push(q.front());
            q.pop();
        }
        i++;
    }

    cout << q.front();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}