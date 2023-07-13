#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a == b && b == c) {
        cout << 10000 + (a * 1000);
    }
    else if ((a == b && a != c) || (a == c && a != b)) {
        cout << 1000 + (a * 100);
    }
    else if (b == c && b != a) {
        cout << 1000 + (b * 100);
    }
    else {
        cout << max({a, b, c}) * 100;
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}