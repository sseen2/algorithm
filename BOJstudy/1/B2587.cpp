#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num[5];
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> num[i];
        sum += num[i];
    }
    sort(num, num + 5);
    cout << (sum / 5) << "\n" << num[2];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
}