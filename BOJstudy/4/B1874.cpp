#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, idx = 0; cin >> n;
    int a[n];
    string ans = "";
    stack<int> s;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        s.push(i);
        ans += "+\n";
        while(!s.empty() && s.top() == a[idx]) {
            ans += "-\n";
            idx++;
            s.pop();
        }
    }

    if (s.empty()) cout << ans;
    else cout << "NO";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t = 1;
  //cin >> t;
  while(t--)
    solve();
}