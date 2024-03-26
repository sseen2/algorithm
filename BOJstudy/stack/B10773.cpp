#include <bits/stdc++.h>
using namespace std;
#define ll long long
stack<int> s;
int sum;

void solve() {
    int n; cin >> n;
    if (n == 0) {
        if (!s.empty()) s.pop();
    }  
    else s.push(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum << '\n';
    
}