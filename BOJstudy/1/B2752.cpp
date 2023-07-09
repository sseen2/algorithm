#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a[3];

    for (int i = 0; i < 3; i++) 
        cin >> a[i];
    
    sort(a, a+3);

    cout << a[0] << " " << a[1] << " " << a[2];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}