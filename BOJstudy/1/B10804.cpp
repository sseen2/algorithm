#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num[20];
    for (int i = 0; i < 20; i++) {
        num[i] = i + 1;
    }
    int end = 10;
    while (end-- > 0) {
        int a, b;
        cin >> a >> b;
        reverse(num + (a - 1), num + b);
    }

    for (int i = 0; i < 20; i++) {
        cout << num[i] << " ";
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}