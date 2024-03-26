#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m, a, cnt = 0; cin >> n >> m;
    deque<int> d;
    for (int i = 1; i <= n; i++) d.push_back(i);

    while (m-- > 0) {
        cin >> a;
        if (!d.empty() && d.front() == a) {
            d.pop_front();
            n--;
        } 
        else {
            int idx = 0;
            for (auto x : d) {
                idx++; if (x == a) break;
            }

            if (idx - 1 <= n - idx + 1) {
                while (d.front() != a) {
                    d.push_back(d.front());
                    d.pop_front();
                    cnt++;
                }
                d.pop_front();
                n--;
            }
            else {
                while (d.front() != a) {
                    d.push_front(d.back());
                    d.pop_back();
                    cnt++;
                }
                d.pop_front();
                n--;
            }
        }
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}